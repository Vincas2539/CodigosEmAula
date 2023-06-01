{- 1 
membro:: Eq a => a -> [a] -> Bool
membro _ [] = False
membro n (a:x)
  | n==a = True
  | otherwise = membro n x

main = do
  let resultado = membro 12 [1,2,3,4,5]
  print resultado
-}

{- 2
rev [] = []
rev (a:x) = rev x ++ [a]

main = do
  let resultado = rev [1,2,3,4]
  print resultado
-}

{- 3
ult:: [Int] -> Int
ult [] = error "Lista Vazia"
ult [x] = x
ult (a:x) = ult x

main = do
  let resultado = ult [1,2,3,4]
  print resultado
-}

{-4
soma2l [] (a:x) = a : soma2l x []
soma2l (a:x) [] = a : soma2l x []
soma2l [] [] = []
soma2l (a:x) (b:y) = (a + b) : soma2l x y

main = do
  let resultado = soma2l [1,1,1,1,1] [2,2,2]
  print resultado
-}

{- 5
del_dup:: Eq t => [t] -> [t]
del_dup [] = []
del_dup (a:[]) = [a]
del_dup (a:x)
  | a == head x = del_dup x
  | otherwise = [a] ++ del_dup x

main = do
  let resultado = del_dup [3,1,2,2,1,1,1,1,2,3]
  print resultado
-}

{- 6
membro:: Eq a => a -> [a] -> Bool
membro _ [] = False
membro n (a:x)
  | n==a = True
  | otherwise = membro n x

del_rep:: Eq t => [t] -> [t]
del_rep [] = []
del_rep (a:x)
  | membro a x == True = del_rep x
  | otherwise = [a] ++ del_rep x


main = do
  let resultado = del_rep [3,1,2,1,2,3]
  print resultado
-}

{- 7
membro:: Eq a => a -> [a] -> Bool
membro _ [] = False
membro n (a:x)
  | n==a = True
  | otherwise = membro n x

inter:: Eq t => [t] -> [t] -> [t]
inter [] [] = []
inter _ [] = []
inter [] _ = []
inter (a:x) y
  | membro a y == True = [a] ++ inter x y
  | otherwise = inter x y

main = do
  let resultado = inter [1,5,6,9,0,12,15] [1,2,6,10,15]
  print resultado
-}

{- 8
delpri:: Eq t => t -> [t] -> [t]
delpri _ [] = []
delpri n (a:x)
  | n == a = x
  | otherwise = [a] ++ delpri n x

main = do
  let resultado = delpri 5 [1,3,3,5,5,3,5,6,5,2]
  print resultado
-}

{- 9
delall:: Eq t => t -> [t] -> [t]
delall _ [] = []
delall n (a:x)
  | n == a = delall n x
  | otherwise = [a] ++ delall n x

main = do
  let resultado = delall 5 [1,3,3,5,5,3,5,6,5,2]
  print resultado
-}

