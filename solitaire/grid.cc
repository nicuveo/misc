//
// grid.cc for solitaire
// Made by nicuveo <crucuny@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include "grid.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

Grid::Grid(int size, Cell c, const Position& last)
  : cells_(size * size, c), last_(last), size_(size)
{
}


bool Grid::is_similar_to(const Grid& that) const
{
  return this->cells_ == that.cells_;
}


void Grid::compute()
{
  occupied_cells_ = 0;
  for (unsigned index = 0; index < cells_.size(); ++index)
    occupied_cells_ += cells_[index] == cell::FULL ? 1 : 0;
}


Grid Grid::chomp(const Position& p0, Direction d) const
{
  assert(chompable(p0, d));

  Position p1 = p0 + d;
  Position p2 = p1 + d;
  Grid res = *this;

  res.cell(p0) = cell::EMPTY;
  res.cell(p1) = cell::EMPTY;
  res.cell(p2) = cell::FULL;

  res.occupied_cells_ -= 1;

  return res;
}


bool Grid::chompable(const Position& p0, Direction d) const
{
  Position p1 = p0 + d;
  Position p2 = p1 + d;

  return
    valid(p0) and
    valid(p1) and
    valid(p2) and
    cell(p0) == cell::FULL and
    cell(p1) == cell::FULL and
    cell(p2) == cell::EMPTY;
}


std::ostream& operator<<(std::ostream& ostr, const Grid& g)
{
  for (int y = 0; y < g.size_; ++y)
  {
    ostr << '[';
    for (int x = 0; x < g.size_; ++x)
      switch (g.cell(pos::create(x, y)))
      {
	case cell::INVALID:
	  ostr << ' ';
	  break;
	case cell::EMPTY:
	  ostr << '.';
	  break;
	case cell::FULL:
	  ostr << 'X';
	  break;
	default:
	  break;
      }
    ostr << ']' << std::endl;
  }

  return ostr;
}
