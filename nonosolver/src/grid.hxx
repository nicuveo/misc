//
// grid.hxx for nonosolver
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef GRID_HXX_
# define GRID_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "grid.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

inline unsigned
Grid::rows() const
{
  return r_;
}

inline unsigned
Grid::cols() const
{
  return c_;
}


inline const std::vector<unsigned>&
Grid::row_data(unsigned index) const
{
  assert(index < r_);
  return r_indicies_[index];
}

inline const std::vector<unsigned>&
Grid::col_data(unsigned index) const
{
  assert(index < c_);
  return c_indicies_[index];
}


inline const Cell&
Grid::cell(unsigned r, unsigned c) const
{
  assert(r < r_);
  assert(c < c_);
  return grid_[r * c_ + c];
}



#endif /* !GRID_HXX_ */
