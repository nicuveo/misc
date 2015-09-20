//
// position.hh for solitaire
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef POSITION_HH_
# define POSITION_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <algorithm>



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

typedef std::pair<int, int> Position;

namespace pos
{

  inline Position create(int x, int y) { return std::make_pair(x, y); }
  inline int x(const Position& p)      { return p.first;              }
  inline int y(const Position& p)      { return p.second;             }

}



#endif /* !POSITION_HH_ */
