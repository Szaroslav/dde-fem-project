module Lib
    ( someFunc
    ) where

someFunc :: Int -> IO ()
someFunc n = putStrLn $ "e_1 = " ++ show (fromIntegral n / 3.0) ++ "x, -" ++ show (fromIntegral n / 3.0) ++ "(x - " ++ show (fromIntegral (2 * n) / 3.0) ++ ")"
