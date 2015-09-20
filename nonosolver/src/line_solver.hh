//
// line_solver.hh for nonosolver
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef LINE_SOLVER_HH_
# define LINE_SOLVER_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <vector>
# include "cell.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

class LineSolver
{
  public:
    static void solve(std::vector<Cell>&, const std::vector<unsigned>&);

  private:
    typedef std::pair<unsigned, unsigned> Range;

    LineSolver(std::vector<Cell>&, const std::vector<unsigned>&);

    void run();
    void compute_free_space();
    void compute_ranges();
    void shrink_ranges();
    void fill_ranges();
    void fill_line();

    void set(unsigned index, Cell v);
    Cell get(unsigned index);

    unsigned known() const;

    unsigned known_;
    std::vector<Cell>& line_;
    std::vector<Range> bounds_;
    std::vector<int> free_space_;
    const std::vector<unsigned>& data_;
};



#endif /* !LINE_SOLVER_HH_ */
