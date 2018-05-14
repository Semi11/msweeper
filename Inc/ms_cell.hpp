#pragma once

#include "ms_cell_state.hpp"

class Cell{
  private:
  bool opened;
  bool M;
  int aroundMNum;
  const static int AROUND_CELL_NUM = 8;
  CellState state;
  
  public:
  Cell(): opened(false),M(false),aroundMNum(0),state(CLOSE){}
  Cell(const Cell &c): opened(c.opened),M(c.M),aroundMNum(c.aroundMNum),state(c.state){}
  bool isOpened() const{return opened;}
  bool hasM() const{return M;}
  bool open();
  void setM(){M = true;}
  void incrementMCount();
  int getAroundMNum(){return aroundMNum;}
  CellState getState(){return state;}
};
