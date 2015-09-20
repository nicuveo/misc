//
// grids.cc for solitaire
// Made by nicuveo <crucuny@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include "grids.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

EnglishGrid::EnglishGrid()
  : Grid(7, cell::FULL, pos::create(3, 3))
{
  cell(pos::create(0, 0)) = cell::INVALID;
  cell(pos::create(0, 1)) = cell::INVALID;
  cell(pos::create(1, 0)) = cell::INVALID;
  cell(pos::create(1, 1)) = cell::INVALID;

  cell(pos::create(5, 0)) = cell::INVALID;
  cell(pos::create(5, 1)) = cell::INVALID;
  cell(pos::create(6, 0)) = cell::INVALID;
  cell(pos::create(6, 1)) = cell::INVALID;

  cell(pos::create(0, 5)) = cell::INVALID;
  cell(pos::create(0, 6)) = cell::INVALID;
  cell(pos::create(1, 5)) = cell::INVALID;
  cell(pos::create(1, 6)) = cell::INVALID;

  cell(pos::create(5, 5)) = cell::INVALID;
  cell(pos::create(5, 6)) = cell::INVALID;
  cell(pos::create(6, 5)) = cell::INVALID;
  cell(pos::create(6, 6)) = cell::INVALID;

  cell(last_) = cell::EMPTY;

  compute();
}

TestGrid::TestGrid()
  : Grid(5, cell::EMPTY, pos::create(4, 0))
{
  occupied_cells_ = 7;

  cell(pos::create(0, 0)) = cell::FULL;
  cell(pos::create(0, 1)) = cell::FULL;
  cell(pos::create(0, 3)) = cell::FULL;

  cell(pos::create(1, 4)) = cell::FULL;
  cell(pos::create(3, 4)) = cell::FULL;

  cell(pos::create(4, 1)) = cell::FULL;
  cell(pos::create(4, 3)) = cell::FULL;

  compute();
}
