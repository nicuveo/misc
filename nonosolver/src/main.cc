//
// main.cc for nonosolver
// Made by nicuveo <crucuny@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include <iostream>
#include "solver.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

int
main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cerr << "usage: " << *argv << " file" << std::endl;
    return 1;
  }

  try
  {
    Grid g(argv[1]);
    Solver s(g);

    s.run();
    std::cout << "result:" << std::endl;
    g.print();
  }
  catch (const char* s)
  {
    std::cerr << "error: " << s << std::endl;
    return 2;
  }

  return 0;
}
