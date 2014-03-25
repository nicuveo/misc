-- imports

import qualified Data.Sequence as S
import qualified Data.Foldable as F
import qualified Data.Tree as T
import qualified Data.Map as M
import Control.Applicative
import Control.Monad
import Data.Maybe
import Data.Ratio



-- types

data Card = King | Queen | Fool | Thief | Bishop deriving (Eq, Ord, Show, Enum, Bounded)
type ProbableCard = M.Map Card (Ratio Int)
type Distribution = S.Seq Card
type Game = T.Tree Distribution



-- tree functions

isLeaf :: T.Tree a -> Bool
isLeaf = null . T.subForest

leaves :: T.Tree a -> [a]
leaves tree@(T.Node val subs)
  | isLeaf tree = [val]
  | otherwise = concat $ fmap leaves subs

mapTreeLeaves :: (a -> T.Tree a) -> T.Tree a -> T.Tree a
mapTreeLeaves func tree@(T.Node val subs)
  | isLeaf tree = func val
  | otherwise = tree { T.subForest = mapForestLeaves func subs }

mapForestLeaves :: (a -> T.Tree a) -> T.Forest a -> T.Forest a
mapForestLeaves func = map (mapTreeLeaves func)

pruneTreeLeaves :: (a -> Bool) -> T.Tree a -> Maybe (T.Tree a)
pruneTreeLeaves func tree@(T.Node val subs)
  | isLeaf tree = if func val then Nothing else Just tree
  | otherwise = if null nsubs then Nothing else Just tree { T.subForest = nsubs }
  where nsubs = pruneForestLeaves func subs

pruneForestLeaves :: (a -> Bool) -> T.Forest a -> T.Forest a
pruneForestLeaves f = mapMaybe (pruneTreeLeaves f)



-- cards functions

swapCards :: (Int, Int) -> Distribution -> Distribution
swapCards (p1, p2) dist = S.update p1 v2 $ S.update p2 v1 dist
  where v1 = S.index dist p1
        v2 = S.index dist p2

allCards :: Distribution
allCards = S.fromList [minBound..]

makeGame :: Distribution -> Game
makeGame d = T.Node d []



-- game functions

swap :: (Int, Int) -> Game -> Game
swap cs = mapTreeLeaves (\d -> T.Node d [makeGame d, makeGame $ swapCards cs d])

reveal :: (Int, Card) -> Game -> Game
reveal (i, c) = fromJust . pruneTreeLeaves (\d -> S.index d i /= c)

probability :: Int -> Game -> ProbableCard
probability i g = foldr (\c -> M.insertWith (+) c (1 % nc)) M.empty cs
  where cs = map (`S.index` i) $ leaves g
        nc = length cs



-- test

main = do
  let p = putStrLn . T.drawTree . fmap show
  let g0 = makeGame allCards
  let g1 = reveal (1, Fool) $ swap (0, 1) $ swap (0, 2) $ swap (2, 3) $ swap (4, 0) g0
  let g2 = swap (1, 3) $ swap (4, 2) g1
  p g1
  p g2
  putStrLn $ unlines $ map (show . (`probability` g2)) [0..4]
