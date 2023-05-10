{-
-- EPITECH PROJECT, 2022
-- imageCompressor
-- File description:
-- Main.hs
-}
module Main (main) where

import           System.Environment (getArgs)
import           System.Random (randomRIO)
import           Data.List (sortOn)
import           Control.Monad (replicateM)
import           Data.List (minimumBy)
import           Data.Ord (comparing)
import           Text.Read (readEither)


-- ==================== PARCING ====================
type Color = (Int, Int, Int)

type Coord = (Int, Int)

type Pixel = (Coord, Color)

type Centroid = (Pixel, [Pixel])

data Args = Args { n :: Int, l :: Float, f :: FilePath }

splitOn :: Char -> String -> [String]
splitOn separator input = let
    splitHelper "" acc = reverse acc
    splitHelper str acc =
      let
        (x, xs) = break (== separator) str
        nextStr = drop 1 xs
      in
        splitHelper nextStr (x : acc)
  in
    splitHelper input []

parseLine :: String -> Either String (Coord, Color)
parseLine input = case words input of
    [coordStr, colorStr] -> do
        coord <- parseCoord coordStr
        color <- parseColor colorStr
        return (coord, color)
    _ -> Left "Invalid input format"

parseCoord :: String -> Either String Coord
parseCoord input = case splitOn ',' input of
    [xStr, yStr] -> do
        x <- readEither (tail xStr)
        y <- readEither (init yStr)
        return (x, y)
    _ -> Left "Invalid coordinate format"

parseColor :: String -> Either String Color
parseColor input = case splitOn ',' input of
    [rStr, gStr, bStr] -> do
        r <- readEither (tail rStr)
        g <- readEither gStr
        b <- readEither (init bStr)
        return (r, g, b)
    _ -> Left $ "Invalid color format" ++ input

parseFile :: String -> IO [Pixel]
parseFile filename = do
  input <- readFile filename
  let parsedLines = map parseLine (lines input)
  case sequence parsedLines of
    Left errMsg -> fail errMsg
    Right pixels -> return pixels

parseArgs :: [String] -> Args
parseArgs args = case args of
  ["-n", n, "-l", l, "-f", f] -> Args (read n) (read l) f
  -- ["-n", n, "-f", l, "-l", f] -> Args (read n) f (read l)
  -- ["-l", n, "-n", l, "-f", f] -> Args (read l) (read n) f
  -- ["-l", n, "-f", l, "-n", f] -> Args (read l) f (read n)
  -- ["-f", n, "-l", l, "-n", f] -> Args f (read l) (read n)
  -- ["-f", n, "-n", l, "-l", f] -> Args f (read n) (read l)
  _ -> error "Invalid arguments"

randomCentroid :: [Pixel] -> IO Centroid
randomCentroid pixels = do
  pixel <- randomPixel pixels
  return (pixel, [])

randomPixel :: [Pixel] -> IO Pixel
randomPixel pixels = do
  index <- randomRIO (0, length pixels - 1)
  return (pixels !! index)

-- ==================== ALGO ====================
kMeans :: [Centroid] -> [Pixel] -> Float -> [Centroid]
kMeans centroids pixels limit =
  let pixelMap = assignPixels centroids pixels
      newCentroids = calculateCentroids pixelMap
      colorDistance (c1, _) (c2, _) = eclD (snd c1) (snd c2)
      distance = zipWith colorDistance centroids newCentroids
  in if all (< limit) distance
     then newCentroids
     else kMeans newCentroids pixels limit

--to calculate euclidean distance
eclD :: Color -> Color -> Float
eclD (r1, g1, b1) (r2, g2, b2) =
  let r = fromIntegral $ r2 - r1
      g = fromIntegral $ g2 - g1
      b = fromIntegral $ b2 - b1
  in sqrt (r ** 2 + g ** 2 + b ** 2)

-- to calculate centroid
clCent :: Pixel -> [Centroid] -> Centroid
clCent pix cent = minimumBy (comparing (eclD (snd pix).snd.fst)) cent

assignPixels :: [Centroid] -> [Pixel] -> [Centroid]
assignPixels cents pixels = map updateCentroid cents
  where updateCentroid (cent, _) = (cent, newPix)
          where newPix = filter (\p -> fst (clCent p cents) == cent) pixels

calculateCentroids :: [Centroid] -> [Centroid]
calculateCentroids centroids = map calculateCentroid centroids

calculateCentroid :: Centroid -> Centroid
calculateCentroid (a, []) = (a, [])
calculateCentroid (_, pixels) = let newPixel = averagePixel pixels
                                in (newPixel, pixels)

averagePixel :: [Pixel] -> Pixel
averagePixel pixels = let (coords, colors) = unzip pixels
                          (rAvg, gAvg, bAvg) = averageColors colors
                          coordAvg = averageCoords coords
                      in (coordAvg, (rAvg, gAvg, bAvg))

averageCoords :: [Coord] -> Coord
averageCoords coords = let (xCoords, yCoords) = unzip coords
                           xAvg = sum xCoords `div` length coords
                           yAvg = sum yCoords `div` length coords
                       in (xAvg, yAvg)

averageColors :: [Color] -> Color
averageColors colors =
  let (rVals, gVals, bVals) = unzip3 colors
      rAvg = sum rVals `div` length colors
      gAvg = sum gVals `div` length colors
      bAvg = sum bVals `div` length colors
  in (rAvg, gAvg, bAvg)

-- ==================== MAIN ====================
showCentroids :: [Centroid] -> String
showCentroids centroids = concatMap
  (\((_, color), pixels) -> "--\n"
   ++ show color
   ++ "\n-\n"
   ++ concatMap
     (\(coord, color) -> show coord ++ " " ++ show color ++ "\n")
     pixels)
  centroids

main :: IO ()
main = do
  args <- getArgs
  let parsedArgs = parseArgs args
  pixels <- parseFile (f parsedArgs)
  let numCentroids = n parsedArgs
      limit = l parsedArgs
  centroids <- replicateM numCentroids (randomCentroid pixels)
    >>= return . sortOn fst
  let finalCentroids = kMeans centroids pixels limit
  putStrLn $ showCentroids finalCentroids