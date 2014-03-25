# imports

import qualified Data.List as L
import qualified Data.Map as M
import Data.Ratio



# types

data Card = King | Queen | Fool deriving (Eq, Ord, Show, Enum, Bounded)
type Hand = M.Map Card Rational



# functions

allCards :: [Card]
allCards = [minBound..]

startingHand :: Card -> Hand
startingHand card = M.fromList $ map cardProba allCards
  where
    cardProba c
      | card == c = (c, 1)
      | otherwise = (c, 0)

swapHands :: Hand -> Hand -> Hand
swapHands = M.unionWith mean
  where
    mean p1 p2 = (p1 + p2) / 2

revealAs :: Card -> Hand -> Hand
revealAs c _ = startingHand c

revealAsNot :: Card -> Hand -> Hand
revealAsNot c = norm . clean
  where
    norm  h = M.map (/ (total h)) h
    clean h = M.alter zero c h
    total h = M.foldl (+) 0 h
    zero    = \_ -> Just 0

swap :: (Int, Int) -> [Hand] -> [Hand]
swap (p1, p2) hands = map alter $ zip [0..] hands
  where
    nh = swapHands (hands !! p1) (hands !! p2)
    alter (i, h)
      | i `elem` [p1, p2] = nh
      | otherwise         = h

reveal :: (Int, Card) -> [Hand] -> [Hand]
reveal (index, card) = map alter . zip [0..]
  where
    alter (i, h)
      | i == index = revealAs card h
      | otherwise  = revealAsNot card h



# test

main = do
  let pShow p = (show $ fst p) ++ ": " ++ (show $ snd p)
  let hShow h = "(" ++ (concat $ L.intersperse ", " $ map pShow $ M.toAscList h) ++ ")"
  let hands = map startingHand allCards
  let print = putStrLn . hShow
  let prints = sequence . map print
  let game = reveal (0, Fool) . swap (0, 1) . swap (0, 2) . swap (1, 2) . swap (0, 2)

  prints $ game hands
