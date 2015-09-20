//
// direction.hh for solitaire
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef DIRECTION_HH_
# define DIRECTION_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "position.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace direction
{

  enum Type
  {
    UP,
    LEFT,
    DOWN,
    RIGHT,

    SIZE
  };

}

typedef direction::Type Direction;
typedef std::pair<Position, Direction> Vector;


Position operator+(const Position& p, const Direction&);


#endif /* !DIRECTION_HH_ */
