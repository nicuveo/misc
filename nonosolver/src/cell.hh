//
// cell.hh for nonosolver
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef CELL_HH_
# define CELL_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <cassert>



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace cell
{


  enum State
  {
    UNKNOWN,
    FILLED,
    EMPTY
  };


  bool set(State s);
  bool available(State s);


}


typedef cell::State Cell;



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "cell.hxx"


#endif /* !CELL_HH_ */
