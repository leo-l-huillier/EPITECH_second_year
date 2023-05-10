{--
-- EPITECH PROJECT, 2023
-- wolfram
-- File description:
-- file.hs
--}

import System.Exit (exitWith, ExitCode(..))
import System.Environment (getArgs)
import Data.Maybe (fromJust, fromMaybe, isJust, isNothing)
import Data.Bits (Bits(Bite))
import System.IO (hPutStrLn, stderr)
import Text.Read

data Stock = Stock {
    stocked :: [[Bool]],
    index :: Int
} deriving (Show)

data Pattern = Pattern {
    pat0 :: Bool,
    pat1 :: Bool,
    pat2 :: Bool,
    pat3 :: Bool,
    pat4 :: Bool,
    pat5 :: Bool,
    pat6 :: Bool,
    pat7 :: Bool
} deriving (Show)

data Globale = Globale {
    mid :: Int,
    width :: Int,
    height :: Int,
    rowLen :: Int
} deriving (Show)

data Parameter = Parameter {
    orule :: Maybe Int,
    ostart :: Int,
    olines :: Maybe Int,
    owin :: Int,
    omove :: Int
} deriving (Show)

defaultParameter :: Parameter
defaultParameter = Parameter {
    orule = Nothing,
    ostart = 0,
    olines = Nothing,
    owin = 80,
    omove = 0
}

initStock :: [[Bool]] -> Globale -> Stock
initStock grid Globale = Stock {
    stocked = replicate (height Globale) (replicate (rowLen Globale) False),
    index = 0
}

setPattern :: Int -> Pattern
setPattern decimal = Pattern {
    pat0 = Bite decimal 0,
    pat1 = Bite decimal 1,
    pat2 = Bite decimal 2,
    pat3 = Bite decimal 3,
    pat4 = Bite decimal 4,
    pat5 = Bite decimal 5,
    pat6 = Bite decimal 6,
    pat7 = Bite decimal 7
}

detectPatern :: Bool -> Bool -> Bool -> Pattern -> Bool
detectPatern False True True pos = pat0 pos
detectPatern False True False pos = pat1 pos
detectPatern False False True pos = pat2 pos
detectPatern True False False pos = pat3 pos
detectPatern True True True pos = pat4 pos
detectPatern True True False pos = pat5 pos
detectPatern True False True pos = pat6 pos
detectPatern False False False pos = pat7 pos

changeValues :: Int -> Int -> Bool -> Stock -> [[Bool]]
changeValues i j newValue Stock = take i (stocked Stock) ++
                                [take j (stocked Stock !! i) ++ [newValue] ++ drop (j + 1) (stocked Stock !! i)] ++
                                drop (i + 1) (stocked Stock)

giveStart :: Globale -> Stock -> [[Bool]]
giveStart Globale Stock = changeValues 0 (mid Globale) True (initStock (stocked Stock) Globale)

displayMap :: [[Bool]] -> IO ()
displayMap grid = mapM_ putStrLn (map (map (\b -> if b then '*' else ' ')) grid)

getOpts :: Parameter -> [String] -> Maybe Parameter
getOpts opt [] = Just opt
getOpts opt (x : xs) = case x of
    "--rule" -> case xs of
        (r : rs) -> getOpts (opt {orule = readMaybe r}) rs
        [] -> Nothing
    "--start" -> case xs of (s : ss) -> getOpts (opt {ostart = read s}) ss

changeChar :: [[Bool]] -> (Int, Int) -> (Bool -> Bool -> Bool -> Pattern -> Bool) -> Bool
changeChar list (x, y) f =
let b1 = if y > 0 && x > 0 then (list !! (x-1)) !! (y-1) else False
b2 = if y > 0 then (list !! x) !! (y-1) else False
b3 = if y > 0 && x < length list - 1 then (list !! (x+1)) !! (y-1) else False
p = Pattern (list !! x !! y)
(if y > 0 then (list !! x) !! (y-1) else False)
(if y < length (head list) - 1 then (list !! x) !! (y+1) else False)
b1
(if x > 0 then (list !! (x-1)) !! y else False)
(if x < length list - 1 then (list !! (x+1)) !! y else False)
b3
(if x > 0 && y < length (head list) - 1 then (list !! (x-1)) !! (y+1) else False)
in f (pat0 p) (pat1 p) (pat2 p) p || f (pat1 p) (pat2 p) (pat3 p) p
|| f (pat2 p) (pat3 p) (pat4 p) p || f (pat3 p) (pat4 p) (pat5 p) p
|| f (pat4 p) (pat5 p) (pat6 p) p || f (pat5 p) (pat6 p) (pat7 p) p

applyChar :: [[Bool]] -> (Bool -> Bool -> Bool -> Pattern -> Bool) -> [[Bool]]
applyChar [] _ = []
applyChar (x : xs) f =
let nextRow [] _ _ _ = []
nextRow (y : ys) acc left accP = let p = setPattern accP
newValue = f left acc y p
in newValue : nextRow ys newValue y (accP shiftL 1 .|. fromEnum y)
in x : applyChar xs f' (nextRow x False False 0)
where f' = changeChar (x : xs)

runCA :: Parameter -> [[Bool]] -> IO ()
runCA _ [] = return ()
runCA opt (x : xs) = do
displayMap [x]
_ <- getLine
runCA opt (applyChar (x : xs) rule)
where
rule = detectPatern False

main :: IO ()
main = do
args <- getArgs
let Parameter = fromMaybe defaultParameter (getOpts defaultParameter args)
if isNothing (orule Parameter) then errorExit "Rule is missing.\n" else return ()
if isNothing (olines Parameter) then errorExit "Number of lines is missing.\n" else return ()
let Globale = Globale { mid = ostart Parameter,
width = owin Parameter,
height = fromJust (olines Parameter),
rowLen = owin Parameter + 1 }
start = giveStart Globale (initStock [] Globale)
runCA Parameter start
