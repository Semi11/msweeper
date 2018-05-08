#include <iostream>
#include <string>
#include "ms_view.hpp"

void View::dispBoard(const std::vector<CellState> &cellsState, int height, int width)const{
  std::cout << "   ";
  for(int i=0;i<width;i++){
    std::cout << i/10 << i%10 << ' ';
  }
  std::cout << std::endl;
  std::cout << "   ";
  for(int i=0;i<width;i++)std::cout << "___";
  std::cout << std::endl;

  for(int i=0;i<height;i++){
    std::cout << i/10 << i%10 << '|';
    for(int j=0;j<width;j++){
      std::cout << ' ' << VIEW_CELL_LIST.at(cellsState.at(i * width + j)) << ' ';
    }
    std::cout << std::endl;
  }
}
