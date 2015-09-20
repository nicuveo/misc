//
// line_solver.cc for nonosolver
// Made by nicuveo <crucuny@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include "line_solver.hh"
#include "foreach.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

void
LineSolver::solve(std::vector<Cell>& l, const std::vector<unsigned>& d)
{
  LineSolver(l, d).run();
}


LineSolver::LineSolver(std::vector<Cell>& l, const std::vector<unsigned>& d)
  : line_(l), data_(d)
{
  bounds_.resize(d.size());
}


void
LineSolver::run()
{
  unsigned res;

  known_ = known();
  while (true)
  {
    compute_free_space();
    compute_ranges();
    shrink_ranges();
    fill_ranges();
    fill_line();

    res = known();
    if (res == known_)
      break;
    known_ = res;
  }
}

void
LineSolver::compute_free_space()
{
  unsigned index = 0;
  Cell prev = cell::EMPTY;

  free_space_.clear();
  foreach (Cell c, line_)
  {
    if (cell::available(c))
      free_space_.push_back(index);
    else
      if (cell::available(prev))
	free_space_.push_back(-1);
    index += 1;
    prev = c;
  }
}

void
LineSolver::compute_ranges()
{
  unsigned size = data_.size();
  Range limits(0, free_space_.size() - 1);

  for (unsigned i = 0; i < size; ++i)
  {
    bounds_[i].first = limits.first;
    bounds_[size - 1 - i].second = limits.second;
    limits.first += data_[i] + 1;
    limits.second -= data_[size - 1 - i] + 1;
  }
}

void
LineSolver::shrink_ranges()
{
  unsigned size = data_.size();

  for (unsigned i = 0; i < size; ++i)
  {
    while (true)
    {
      Range& r = bounds_[i];
      std::pair<int, int> seps(free_space_.size(), -1);

      for (unsigned j = r.first; j <= r.second; ++j)
	if (free_space_[j] == -1)
	{
	  seps.first  = std::min((int) j, seps.first);
	  seps.second = std::max((int) j, seps.second);
	}

      if (seps.first  - r.first  >= data_[i] and
	  r.second - seps.second >= data_[i])
	break;

      if (seps.first  - r.first  < data_[i])
	r.first = seps.first + 1;
      if (r.second - seps.second < data_[i])
	r.second = seps.second - 1;
    }
  }
}

void
LineSolver::fill_ranges()
{
  bool loop = true;
  unsigned size = data_.size();

  while (loop)
  {
    std::vector<int> overlap(free_space_.size(), -1);

    for (unsigned i = 0; i < size; ++i)
      for (unsigned j = bounds_[i].first; j <= bounds_[i].second; ++j)
	overlap[j] = (overlap[j] == -1 ? i : -2);

    loop = false;
    for (unsigned i = 0; i < overlap.size(); ++i)
      if (get(i) == cell::FILLED && overlap[i] >= 0)
      {
	unsigned index = overlap[i];
	Range r = bounds_[index];

	r.first  = (unsigned) std::max<int>(r.first,  i - data_[index] + 1);
	r.second = (unsigned) std::min<int>(r.second, i + data_[index] - 1);

	if (r != bounds_[index])
	  loop = true;
	bounds_[index] = r;
      }
  }
}

void
LineSolver::fill_line()
{
  unsigned size = data_.size();
  unsigned prev = 0;

  for (unsigned i = 0; i < size; ++i)
  {
    for (unsigned j = prev; j < bounds_[i].first; ++j)
      set(j, cell::EMPTY);

    Range r(bounds_[i].second - data_[i] + 1, bounds_[i].first + data_[i] - 1);
    for (unsigned j = r.first; j <= r.second; ++j)
      set(j, cell::FILLED);

    prev = bounds_[i].second + 1;
  }

  while (prev < free_space_.size())
    set(prev++, cell::EMPTY);
}


void
LineSolver::set(unsigned index, Cell v)
{
  int r = free_space_[index];

  assert(cell::set(v));
  if (r >= 0)
  {
    assert(line_[r] == cell::UNKNOWN or line_[r] == v);
    line_[r] = v;
  }
}

Cell
LineSolver::get(unsigned index)
{
  int r = free_space_[index];

  return (r >= 0 ? line_[r] : cell::EMPTY);
}


unsigned
LineSolver::known() const
{
  unsigned res = 0;

  foreach (Cell c, line_)
    if (cell::set(c))
      res += 1;

  return res;
}
