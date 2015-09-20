//
// cell.hh for solitaire
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef CELL_HH_
# define CELL_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace cell
{

  enum Type
  {
    INVALID,
    EMPTY,
    FULL,

    SIZE
  };

}

typedef cell::Type Cell;



#endif /* !CELL_HH_ */
