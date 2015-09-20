//
// grid.cc for nonosolver
// Made by nicuveo <crucuny@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "grid.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

Grid::Grid(const std::string& filename)
{
  std::ifstream ifs;

  ifs.open(filename.c_str());
  if (not ifs.good())
    throw "file does not exist";

  ifs >> r_ >> c_;

  r_indicies_ = extract(ifs, r_, c_);
  c_indicies_ = extract(ifs, c_, r_);

  ifs.close();

  grid_.resize(r_ * c_, cell::UNKNOWN);
}


std::vector<Cell>
Grid::row(unsigned index) const
{
  std::vector<Cell> res;

  assert(index < r_);
  for (unsigned i = 0; i < c_; ++i)
    res.push_back(cell(index, i));

  return res;
}

std::vector<Cell>
Grid::col(unsigned index) const
{
  std::vector<Cell> res;

  assert(index < c_);
  for (unsigned i = 0; i < r_; ++i)
    res.push_back(cell(i, index));

  return res;
}


void
Grid::cell(unsigned r, unsigned c, const Cell& s)
{
  assert(r < r_);
  assert(c < c_);

  grid_[r * c_ + c] = s;
}


std::vector<std::vector<unsigned> >
Grid::extract(std::ifstream& ifs, unsigned n, unsigned m)
{
  std::vector<std::vector<unsigned> > res;

  for (unsigned i = 0; i < n; ++i)
  {
    std::vector<unsigned> current;
    std::stringstream ss;
    std::string buf;
    unsigned val;
    unsigned sum = 0;
    bool z = false;

    if (!ifs)
      throw "malformed file";

    while (buf.empty())
      std::getline(ifs, buf);

    ss << buf;
    ss >> val;
    while (ss)
    {
      sum += val;
      current.push_back(val);
      ss >> val;
      if (val == 0)
	z = true;
    }

    if (sum + current.size() - 1 > m)
    {
      std::cerr << "at row/col " << i << ": ";
      throw "too many values for row/col";
    }

    if (z and current.size() > 1)
    {
      std::cerr << "at row/col " << i << ": ";
      throw "more than 1 value in list containing 0";
    }

    res.push_back(current);
  }

  return res;
}


void
Grid::print() const
{
  unsigned mr = 0;
  unsigned mc = 0;

  for (unsigned r = 0; r < rows(); ++r)
    if (row_data(r).size() > mr)
      mr = row_data(r).size();
  for (unsigned c = 0; c < cols(); ++c)
    if (col_data(c).size() > mc)
      mc = col_data(c).size();

  for (unsigned r = 0; r < mc; ++r)
  {
    for (unsigned c = 0; c < mr; ++c)
      std::cout << "   ";
    for (unsigned c = 0; c < cols(); ++c)
      if (col_data(c).size() >= mc - r)
	std::cout << std::right << std::setw(3)
		  << col_data(c)[col_data(c).size() - mc + r];
      else
	std::cout << "   ";
    std::cout << std::endl;
  }

  for (unsigned r = 0; r < rows(); ++r)
  {
    for (unsigned c = 0; c < mr; ++c)
      if (row_data(r).size() >= mr - c)
	std::cout << std::right << std::setw(3)
		  << row_data(r)[row_data(r).size() - mr + c];
      else
	std::cout << "   ";

    for (unsigned c = 0; c < cols(); ++c)
      switch (cell(r, c))
      {
	case cell::EMPTY:
	  std::cout << "   ";
	  break;
	case cell::FILLED:
	  std::cout << " ##";
	  break;
	case cell::UNKNOWN:
	  std::cout << " ..";
	  break;
      }

    std::cout << std::endl;
  }
}
