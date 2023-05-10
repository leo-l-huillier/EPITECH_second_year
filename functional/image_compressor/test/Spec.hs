import Test.HUnit
import           System.Environment (getArgs)
import           Control.Monad (when)
import           System.Random (randomRIO)
import           Data.List (sortOn)
import           Control.Monad (replicateM)
import           Data.List (minimumBy)
import           Data.Ord (comparing)
import Control.Monad (void)


type Color = (Int, Int, Int)

type Coord = (Int, Int)

type Pixel = (Coord, Color)

type Centroid = (Pixel, [Pixel])

-- Function to test
eclD :: Color -> Color -> Float
eclD (r1, g1, b1) (r2, g2, b2) =
  let r = fromIntegral $ r2 - r1
      g = fromIntegral $ g2 - g1
      b = fromIntegral $ b2 - b1
  in sqrt (r ** 2 + g ** 2 + b ** 2)

-- Test cases
testCases :: Test
testCases = TestList [
    TestCase $ assertEqual "Test eclD 1" 0.0 (eclD (0,0,0) (0,0,0)),
    TestCase $ assertEqual "Test eclD 2"  5.196152 (eclD (240,240,240) (237,237,237)),
    TestCase $ assertEqual "Test eclD 3"  84.65223 (eclD (46, 89, 51) (12, 156, 12))
  ]

main = do
  runTestTT testCases

