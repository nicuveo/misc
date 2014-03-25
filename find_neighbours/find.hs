import System.Environment
import Control.Monad
import qualified Data.MultiSet as M

distance :: String -> String -> Maybe Int
distance s1 s2
  | length s1 /= length s2 = Nothing
  | otherwise = Just $ M.size $ ss1 M.\\ ss2
  where ss1 = M.fromList s1
        ss2 = M.fromList s2

distance' :: Int -> String -> String -> Bool
distance' i s = test . distance s
  where test (Just x) = x == i
        test Nothing = False

main = do
  [dico, word] <- liftM (take 2) getArgs
  words <- liftM lines $ readFile dico
  putStr $ unlines $ filter (distance' 1 word) words
