//
// solver.hh for solitaire
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef SOLVER_HH_
# define SOLVER_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <list>
# include "grid.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

std::list<Vector> solve(const Grid& g);




#endif /* !SOLVER_HH_ */
