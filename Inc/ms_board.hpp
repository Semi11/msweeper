#pragma once

#include <vector>
#include <ms_cell.hpp>

class Board{
  private:
  std::vector<Cell> cells;
  const int height;
  const int width;

  public:
  Board(int height, int width, int MNum);
  bool openCell(int pos);
  bool openCell(int x, int y);
  bool isMOpened();
  bool isAllCellOpened();
  static int posToX(int pos, int width){return pos % width;}
  static int posToY(int pos, int width){return pos / width;}
  static int xyToPos(int x, int y, int width){return y * width + x;}
<<<<<<< HEAD
  std::vector<CellState> getAllCellState();  
=======
>>>>>>> e5575f398f5db9fae182f873c7718d6757755d20
};
