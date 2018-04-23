#pragma once

#include <vector>

class Board{
  private:
  std::vector<Cell> cells;
  const int height;
  const int width;

  int posToX(int pos) const{return pos % width}
  int posToY(int pos) const{return pos / width}
  int xyToPos(int x, int y) const{return y * width + x}

  public:
  Board(int height, int width, int MNum);
  bool openCell(int pos);
  bool isMOpened();
}
