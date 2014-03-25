-- imports

import qualified Data.Sequence as S
import qualified Data.Foldable as F
import qualified Data.Tree as T
import Control.Applicative
import Control.Monad
import Data.Maybe



-- types

data Card = King | Queen | Fool | Thief | Bishop deriving (Eq, Ord, Show, Enum, Bounded)
type Distribution = [Card]
type Game = T.Tree Distribution



-- functions

swapList :: (Int, Int) -> [a] -> [a]
swapList c@(p1, p2) list = F.toList $ S.update p1 v2 $ S.update p2 v1 $ S.fromList list
  where v1 = list !! p1
        v2 = list !! p2

isLeaf :: Game -> Bool
isLeaf = null . T.subForest

allCards :: Distribution
allCards = [minBound..]

startGame :: Distribution -> Game
startGame d = T.Node d []

swap :: (Int, Int) -> Game -> Game
swap c@(p1, p2) game@(T.Node dist subf)
  | isLeaf game = game { T.subForest = [game, game { T.rootLabel = swapList c dist } ] }
  | otherwise   = game { T.subForest = map (swap c) subf }

reveal :: (Int, Card) -> Game -> Game
reveal c = fromJust . reveal' c

reveal' :: (Int, Card) -> Game -> Maybe Game
reveal' c@(p, v) game@(T.Node dist subf)
  | isLeaf game = (if dist !! p == v then Just game else Nothing)
  | otherwise   = (if null nsubf then Nothing else Just game { T.subForest = nsubf })
  where nsubf = catMaybes $ map (reveal' c) subf



-- test

main = do
  let p = putStrLn . T.drawTree . fmap show
  let g = swap (0, 1) $ swap (0, 2) $ startGame allCards
  p g
  p $ reveal (1, Fool) g
