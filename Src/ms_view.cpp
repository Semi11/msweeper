#include <iostream>
#include "ms_view.hpp"

void View::dispBoard(const std::vector<CellState> &cellsState, int height, int width)const{
  for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
      std::cout << VIEW_CELL_LIST.at(cellsState.at(i * width + j));
    }
    std::cout << std::endl;
  }
}
