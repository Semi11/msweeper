#pragma once

#include <time.h>
#include "ms_board.hpp"

class Game{
  private:
  clock_t time;
  
  public:
  bool gameMain();  
  static int inputNum();
};
