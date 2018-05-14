//cell.cpp
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
  if(++aroundMNum > AROUND_CELL_NUM) throw std::range_error("error in incrementMCount");
}
