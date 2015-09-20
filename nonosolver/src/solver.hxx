//
// solver.hxx for nonosolver
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef SOLVER_HXX_
# define SOLVER_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "solver.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

inline Solver::Genre
Solver::swap(Genre g)
{
  return g == ROW ? COL : ROW;
}


inline std::vector<Cell>
Solver::line(Genre g, unsigned i) const
{
  return (g == ROW ? g_.row(i) : g_.col(i));
}

inline const std::vector<unsigned>&
Solver::data(Genre g, unsigned i) const
{
  return (g == ROW ? g_.row_data(i) : g_.col_data(i));
}



#endif /* !SOLVER_HXX_ */
