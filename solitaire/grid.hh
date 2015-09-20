//
// grid.hh for solitaire
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef GRID_HH_
# define GRID_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <vector>
# include <ostream>
# include "cell.hh"
# include "direction.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

class Grid
{
  public:
    int remaining() const;
    bool finished() const;

    bool is_similar_to(const Grid& g) const;

    Cell operator()(int x, int y) const;
    Cell operator()(const Position& p) const;

    Grid chomp(int x, int y, Direction d) const;
    Grid chomp(const Position& p, Direction d) const;
    Grid chomp(const Vector& v) const;

    bool valid(const Position& p) const;
    bool valid(int x, int y) const;

    template <typename T>
    void yield_chompables(const T& block) const;
    template <typename T>
    void queue_chompables(T& container) const;

  protected:
    friend std::ostream& operator<<(std::ostream& ostr, const Grid& g);

    Grid(int size, Cell c, const Position& l);

    void compute();

    bool chompable(const Position& p, Direction d) const;

    Cell  cell(const Position& p) const;
    Cell& cell(const Position& p);

    std::vector<Cell> cells_;
    Position last_;
    int occupied_cells_;
    int size_;
};


std::ostream& operator<<(std::ostream& ostr, const Grid& g);



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "grid.hxx"



#endif /* !GRID_HH_ */
