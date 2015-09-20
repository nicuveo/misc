//
// solver.hh for nonosolver
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef SOLVER_HH_
# define SOLVER_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <set>
# include <queue>
# include "grid.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

class Solver
{
  public:
    Solver(Grid& g);

    void run();

  private:
    enum Genre
    {
      ROW,
      COL
    };

    static Genre swap(Genre);

    std::vector<Cell> line(Genre g, unsigned index) const;
    const std::vector<unsigned>& data(Genre g, unsigned index) const;

    void solve(Genre g, unsigned i);
    void set(Genre g, unsigned i1, unsigned i2, Cell c);

    void todo(const std::pair<Genre, unsigned>&);
    void done();

    Grid& g_;
    std::queue<std::pair<Genre, unsigned> > todo_;
    std::set<std::pair<Genre, unsigned> > todo_set_;
};



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "solver.hxx"



#endif /* !SOLVER_HH_ */
