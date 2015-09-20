//
// direction.cc for solitaire
// Made by nicuveo <crucuny@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include <cassert>
#include "direction.hh"
#include "error.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

Position operator+(const Position& p, const Direction& d)
{
  switch (d)
  {
    case direction::UP:
      return pos::create(pos::x(p), pos::y(p) - 1);
    case direction::LEFT:
      return pos::create(pos::x(p) - 1, pos::y(p));
    case direction::DOWN:
      return pos::create(pos::x(p), pos::y(p) + 1);
    case direction::RIGHT:
      return pos::create(pos::x(p) + 1, pos::y(p));
    default:
      ERROR(" invalid direction");
  }
  return p;
}
