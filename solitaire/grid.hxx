//
// grid.hxx for solitaire
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef GRID_HXX_
# define GRID_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <cassert>
# include "grid.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

inline int Grid::remaining() const
{
  return occupied_cells_;
}

inline bool Grid::finished() const
{
  return remaining() == 1 and cell(last_) == cell::FULL;
}


inline Cell Grid::operator()(int x, int y) const
{
  assert(valid(x, y));
  return cells_[y * size_ + x];
}

inline Cell Grid::operator()(const Position& p) const
{
  return (*this)(pos::x(p), pos::y(p));
}


inline Grid Grid::chomp(int x, int y, Direction d) const
{
  return chomp(pos::create(x, y), d);
}

inline Grid Grid::chomp(const Vector& v) const
{
  return chomp(v.first, v.second);
}


inline bool Grid::valid(const Position& p) const
{
  return valid(pos::x(p), pos::y(p));
}

inline bool Grid::valid(int x, int y) const
{
  return x >= 0 and x < size_ and y >= 0 and y < size_;
}


template <typename T>
void Grid::yield_chompables(const T& block) const
{
  for (int y = 0; y < size_; ++y)
    for (int x = 0; x < size_; ++x)
    {
      if (chompable(pos::create(x, y), direction::UP))
	block(pos::create(x, y), direction::UP);
      if (chompable(pos::create(x, y), direction::LEFT))
	block(pos::create(x, y), direction::LEFT);
      if (chompable(pos::create(x, y), direction::DOWN))
	block(pos::create(x, y), direction::DOWN);
      if (chompable(pos::create(x, y), direction::RIGHT))
	block(pos::create(x, y), direction::RIGHT);
    }
}

template <typename T>
void Grid::queue_chompables(T& container) const
{
  for (int y = 0; y < size_; ++y)
    for (int x = 0; x < size_; ++x)
    {
      if (chompable(pos::create(x, y), direction::UP))
	container.push_back(Vector(pos::create(x, y), direction::UP));
      if (chompable(pos::create(x, y), direction::LEFT))
	container.push_back(Vector(pos::create(x, y), direction::LEFT));
      if (chompable(pos::create(x, y), direction::DOWN))
	container.push_back(Vector(pos::create(x, y), direction::DOWN));
      if (chompable(pos::create(x, y), direction::RIGHT))
	container.push_back(Vector(pos::create(x, y), direction::RIGHT));
    }
}


inline Cell Grid::cell(const Position& p) const
{
  return (*this)(p);
}

inline Cell& Grid::cell(const Position& p)
{
  assert(valid(p));
  return cells_[pos::y(p) * size_ + pos::x(p)];
}



#endif /* !GRID_HXX_ */
