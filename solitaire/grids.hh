//
// grids.hh for solitaire
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef GRIDS_HH_
# define GRIDS_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "grid.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

class EnglishGrid : public Grid
{
  public:
    EnglishGrid();
};

class TestGrid : public Grid
{
  public:
    TestGrid();
};



#endif /* !GRIDS_HH_ */
