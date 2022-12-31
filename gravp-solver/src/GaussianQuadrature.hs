module GaussianQuadrature (integrateQuad2) where

-- Integration using gaussian quadratures with 2 points
integrateQuad2 :: (Fractional a) => a -> a -> (a -> a) -> a
integrateQuad2 a b f =  c1 * w * ((f $ c1 * x1 + c2) + (f $ c1 * x2 + c2))
    where x1 = 0.57735026919
          x2 = -0.57735026919
          w  = 1
          c1 = (b - a) / 2
          c2 = (a + b) / 2