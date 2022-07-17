import Data.Ratio

main = do
   line <- getLine
   let 
        num = read (line) :: Integer
        sq = (getSqrt num)
        str = show sq
        (nume, floa) = splitAt ((length str) - 50) str
   putStrLn (nume ++ "." ++ floa)

run n 0 = n
run n t = 
    (n + y * y) `div` (2 * y) 
    where y = run n (t - 1)

getSqrt x 
    | (y `mod` 10) >= 5 = 
        (y) `div` 10 + 1
    | otherwise = y `div` 10
    where y = run (x * 10^102) 200
     
