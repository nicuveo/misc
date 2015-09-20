//
// solver.cc for nonosolver
// Made by nicuveo <crucuny@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include <iostream>
#include "line_solver.hh"
#include "foreach.hh"
#include "solver.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

Solver::Solver(Grid& g)
  : g_(g)
{
}


void
Solver::run()
{
  assert(todo_.empty());

  for (unsigned i = 0; i < g_.rows(); ++i)
    todo(std::make_pair(ROW, i));
  for (unsigned i = 0; i < g_.cols(); ++i)
    todo(std::make_pair(COL, i));

  while (not todo_.empty())
  {
    solve(todo_.front().first, todo_.front().second);
    done();
  }
}


void
Solver::solve(Genre g, unsigned i)
{
  const std::vector<unsigned>& d = data(g, i);
  std::vector<Cell> l = line(g, i);

  assert(d.size());

//   std::cout << "solving " << (g == ROW ? "row " : "col ")
// 	    << i << ": " << std::endl;

  if (d[0] == 0)
    for (unsigned j = 0; j < l.size(); ++j)
      l[j] = cell::EMPTY;
  else
    LineSolver::solve(l, d);

  for (unsigned j = 0; j < l.size(); ++j)
    if (cell::set(l[j]))
      set(g, i, j, l[j]);
}

void
Solver::set(Genre g, unsigned i1, unsigned i2, Cell s)
{
  unsigned r = g == ROW	? i1 : i2;
  unsigned c = g == ROW	? i2 : i1;

  assert(cell::set(s));

  if (not cell::set(g_.cell(r, c)))
  {
    g_.cell(r, c, s);
    todo(std::make_pair(swap(g), i2));
  }
}


void
Solver::todo(const std::pair<Genre, unsigned>& t)
{
  if (todo_set_.count(t) == 0)
  {
    todo_.push(t);
    todo_set_.insert(t);
  }
}

void
Solver::done()
{
  todo_set_.erase(todo_.front());
  todo_.pop();
}
