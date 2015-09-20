//
// main.cc for solitaire
// Made by nicuveo <crucuny@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include <list>
#include <iomanip>
#include <iostream>
#include "grids.hh"
#include "solver.hh"
#include "error.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

int main()
{
  EnglishGrid g;
  std::cout << g;

  const std::list<Vector>& solution = solve(g);

  if (solution.empty())
  {
    std::cout << "no solution found" << std::endl;
    return 1;
  }

  Grid shown = g;
  std::list<Vector>::const_iterator it;
  unsigned index = 0;
  for (it = solution.begin(); it != solution.end(); ++it)
  {
    std::cout << std::endl << "turn " << std::setw(2) << std::right
	      << ++index << ": (" << pos::y(it->first) + 1 << ", "
	      << pos::x(it->first) + 1 << ") -> ";

    switch (it->second)
    {
      case direction::UP:
	std::cout << "up";
	break;
      case direction::LEFT:
	std::cout << "left";
	break;
      case direction::DOWN:
	std::cout << "down";
	break;
      case direction::RIGHT:
	std::cout << "right";
	break;
      default:
	ERROR("unexpected direction");
	break;
    }

    std::cout << std::endl << std::endl;

    shown = shown.chomp(*it);
    std::cout << shown;
  }

  return 0;
}
