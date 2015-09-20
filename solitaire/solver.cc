//
// solver.cc for solitaire
// Made by nicuveo <crucuny@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include <iostream>
#include "solver.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Local code

namespace
{

  bool solve(const Grid& g, std::list<Vector>& res, unsigned level)
  {
    if (g.finished())
      return true;

    std::list<Vector> steps;
    std::list<Vector>::const_iterator it;

    g.queue_chompables(steps);
    for (it = steps.begin(); it != steps.end(); ++it)
    {
      res.push_back(*it);

      // for (unsigned l = 0; l < level; ++l)
      // 	std::cout << " ";
      // std::cout << it->first.first << ", " << it->first.second << ", " << it->second << std::endl;

      if (solve(g.chomp(*it), res, level + 1))
	return true;
      res.pop_back();
    }

    return false;
  }

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

std::list<Vector> solve(const Grid& g)
{
  std::list<Vector> res;

  solve(g, res, 0);

  return res;
}
