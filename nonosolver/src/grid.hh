//
// grid.hh for nonosolver
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef GRID_HH_
# define GRID_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <vector>
# include <string>
# include "cell.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

class Grid
{
  public:
    Grid(const std::string& filename);

    unsigned rows() const;
    unsigned cols() const;

    const std::vector<unsigned>& row_data(unsigned index) const;
    const std::vector<unsigned>& col_data(unsigned index) const;

    std::vector<Cell> row(unsigned index) const;
    std::vector<Cell> col(unsigned index) const;

    const Cell& cell(unsigned r, unsigned c) const;
    void cell(unsigned r, unsigned c, const Cell& s);

    void print() const;

  private:
    static std::vector<std::vector<unsigned> > extract(std::ifstream& ifs, unsigned n, unsigned m);

    unsigned r_;
    unsigned c_;
    std::vector<std::vector<unsigned> > r_indicies_;
    std::vector<std::vector<unsigned> > c_indicies_;
    std::vector<Cell> grid_;
};



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "grid.hxx"



#endif /* !GRID_HH_ */
