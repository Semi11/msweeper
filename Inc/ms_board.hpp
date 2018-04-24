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
  bool isMOpened();
  bool isAllCellOpened();
  static int posToX(int pos, int width){return pos % width;}
  static int posToY(int pos, int width){return pos / width;}
  static int xyToPos(int x, int y, int width){return y * width + x;}
};
