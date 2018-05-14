//view.hpp
#pragma once

#include <vector>
#include "ms_cell_state.hpp"

class View{
  private:
  const std::vector<char> VIEW_CELL_LIST =
  {
    '-','1','2','3','4','5','6','7','8','.','M'
  };
 
  public:
   void dispBoard(const std::vector<CellState> &cellsState, int height, int width)const;
};
