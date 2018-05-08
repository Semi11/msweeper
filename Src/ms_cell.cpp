#include "ms_cell.hpp"
#include <iostream>

bool Cell::open(){
  if(!opened){
    opened = true;
    if(hasM()) state = MINE;
    else state = static_cast<CellState>(aroundMNum);//
    return true;
  }else return false;
}

void Cell::incrementMCount(){
<<<<<<< HEAD
  if(++aroundMNum > AROUND_CELL_NUM) throw std::range_error("error in incrementMCount");
=======
  if(++aroundMNum > AROUND_CELL_NUM) throw 1;
>>>>>>> e5575f398f5db9fae182f873c7718d6757755d20
}
