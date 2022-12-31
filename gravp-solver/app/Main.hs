module Main (main) where

import Lib
import GaussianQuadrature

main :: IO ()
main = putStrLn $ show $ integrateQuad2 0 5 (\x -> x^2)