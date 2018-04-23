#include "ms_cell.hpp"

bool open(){
  if(!opened){
    opened = true;
    return true;
  }else return false;
}

void Cell::incrementMCount{
  if(++aroundMNum > AROUND_CELL_NUM) throw 1;
}
