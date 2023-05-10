import argparse
from typing import List
from functools import cmp_to_key
from operator import itemgetter
from math import sqrt
from typing import List, Tuple
import random

Color = Tuple[int, int, int]
Coord = Tuple[int, int]
Pixel = Tuple[Coord, Color]
Centroid = Tuple[Pixel, List[Pixel]]

def valid_color(c: int) -> bool:
    return 0 <= c <= 255

def pixel_parser(s: str) -> Color:
    if s[0] == "(" and s[-1] == ")":
        s = s[1:-1]
        r, g, b = map(int, s.split(","))
        if not (valid_color(r) and valid_color(g) and valid_color(b)):
            raise argparse.ArgumentTypeError("Invalid pixel")
        return r, g, b
    raise argparse.ArgumentTypeError("Invalid pixel format")

def pixelParser():
    pixel = pixelParser()
    if not valid_color(pixel[0]):
        raise Exception("Invalid red value")
    if not valid_color(pixel[1]):
        raise Exception("Invalid green value")
    if not valid_color(pixel[2]):
        raise Exception("Invalid blue value")
    return pixel

def coord_parser(s):
    if s[0] == "(" and s[-1] == ")":
        s = s[1:-1]
        x, y = map(int, s.split(","))
        return x, y
    raise argparse.ArgumentTypeError("Invalid coord format")

def line_parser(line):
    parts = line.split()
    if len(parts) != 2:
        raise argparse.ArgumentTypeError("Invalid line format")
    return coord_parser(parts[0]), pixel_parser(parts[1])


def parse_file(file_path):
    with open(file_path, "r") as f:
        return [line_parser(line.strip()) for line in f]


def parseArgs(args):
    if len(args) == 6 and args[0] == '-n' and args[2] == '-l' and args[4] == '-f':
        n = int(args[1])
        l = int(args[3])
        f = args[5]
        return args(n, l, f)
    else:
        raise Exception("Invalid arguments")

def randomCentroid(pixels):
    pixel = random.choice(pixels)
    return (pixel, [])

def randomPixel(pixels):
    index = random.randint(0, len(pixels) - 1)
    return pixels[index]

def kMeans(centroids, pixels, limit):
    pixelMap = assignPixels(centroids, pixels)
    newCentroids = calculateCentroids(pixelMap)
    colorDistance = lambda c1, c2: euclideanDistance(c1[1], c2[1])
    distance = [colorDistance(c1, c2) for c1, c2 in zip(centroids, newCentroids)]
    if all(d < limit for d in distance):
        return newCentroids
    else:
        return kMeans(newCentroids, pixels, limit)

def closestCentroid(pixel, centroids):
    return min(centroids, key=lambda c: euclideanDistance(pixel[1], c[1]))

def assignPixels(centroids, pixels):
    def updateCentroid(centroid):
        newAssignedPixels = [p for p in pixels if closestCentroid(p, centroids) == centroid]
        return (centroid[0], newAssignedPixels)
    return list(map(updateCentroid, centroids))

def calculateCentroid(centroid):
    a, pixels = centroid
    if not pixels:
        return (a, [])
    else:
        newPixel = averagePixel(pixels)
        return (newPixel, pixels)

def calculateCentroids(centroids):
    return list(map(calculateCentroid, centroids))

def averagePixel(pixels):
    coords, colors = zip(*pixels)
    r_avg, g_avg, b_avg = average_colors(colors)
    coord_avg = averageCoords(coords)
    return (coord_avg, (r_avg, g_avg, b_avg))

def averageCoords(coords):
    xCoords, yCoords = zip(*coords)
    xAvg = sum(xCoords) // len(coords)
    yAvg = sum(yCoords) // len(coords)
    return (xAvg, yAvg)

def average_colors(colors):
    r_vals, g_vals, b_vals = zip(*colors)
    r_avg = sum(r_vals) // len(colors)
    g_avg = sum(g_vals) // len(colors)
    b_avg = sum(b_vals) // len(colors)
    return (r_avg, g_avg, b_avg)

def euclideanDistance(color1, color2):
    r1, g1, b1 = color1
    r2, g2, b2 = color2
    r = r2 - r1
    g = g2 - g1
    b = b2 - b1
    return sqrt(r ** 2 + g ** 2 + b ** 2)

def showCentroids(centroids):
    output = ""
    for ((_, color), pixels) in centroids:
        output += "--\n" + str(color) + "\n-\n"
        for (coord, color) in pixels:
            output += str(coord) + " " + str(color) + "\n"
    return output

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-n", type=int, required=True)
    parser.add_argument("-l", type=int, required=True)
    parser.add_argument("-f", type=str, required=True)
    args = parser.parse_args()
    pixels = parse_file(args.f)
    centroids = [randomCentroid(pixels) for _ in range(args.n)]
    centroids.sort(key=itemgetter(0))
    finalCentroids = kMeans(centroids, pixels, args.l)
    print(showCentroids(finalCentroids))

main()