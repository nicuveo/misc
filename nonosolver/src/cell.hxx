//
// cell.hxx for nonosolver
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef CELL_HXX_
# define CELL_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "cell.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace cell
{


  inline bool
  set(State s)
  {
    return s != UNKNOWN;
  }

  inline bool
  available(State s)
  {
    return s != EMPTY;
  }


}



#endif /* !CELL_HXX_ */
