#pragma once

#include "ms_cell_state.hpp"

class Cell{
  private:
  bool opened;
  bool M;
  int aroundMNum;
  const static int AROUND_CELL_NUM = 8;
<<<<<<< HEAD
  CellState state;
  
  public:
  Cell(): opened(false),M(false),aroundMNum(0),state(CLOSE){}
  Cell(const Cell &c): opened(c.opened),M(c.M),aroundMNum(c.aroundMNum),state(c.state){}
=======
  
  public:
  Cell(): opened(false),M(false),aroundMNum(0){}
>>>>>>> e5575f398f5db9fae182f873c7718d6757755d20
  bool isOpened() const{return opened;}
  bool hasM() const{return M;}
  bool open();
  void setM(){M = true;}
  void incrementMCount();
  int getAroundMNum(){return aroundMNum;}
<<<<<<< HEAD
  CellState getState(){return state;}
=======
>>>>>>> e5575f398f5db9fae182f873c7718d6757755d20
};
