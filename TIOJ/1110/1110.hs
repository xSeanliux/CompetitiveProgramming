import Data.Int
import Data.List


main = do
    line <- getLine
    let testNum = (head . map read . words) line :: Int
    run testNum

run 0 = return()
run x = do
    line <- getLine
    let str = last $ words $ show line
    getAns str
    run (x - 1)

getAns str = do
    let 
        frq = [(ch, length (filter (==ch) str)) | ch <- ['a'..'z']]
        mxfrq = foldl (\acc x -> max acc (snd x)) 0 frq
        ans = [fst p | p <- frq, (snd p) == mxfrq]
    putStrLn ans
    

