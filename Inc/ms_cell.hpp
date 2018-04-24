#pragma once

class Cell{
  private:
  bool opened;
  bool M;
  int aroundMNum;
  const static int AROUND_CELL_NUM = 8;
  
  public:
  Cell(): opened(false),M(false),aroundMNum(0){}
  bool isOpened() const{return opened;}
  bool hasM() const{return M;}
  bool open();
  void setM(){M = true;}
  void incrementMCount();
  int getAroundMNum(){return aroundMNum;}
};
