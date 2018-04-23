#include "ms_board.hpp"
#include <random>
#include <algorithm>

Board(int height, int width, int MNum):cells(height* width)height(height),width(width){
  //指定個数分Mをセット
  for(int i = 0;i < std::min(cells.size, MNum);i++) cells.at(i).setM();

  //ボードをシャッフル
  std::random_device seed_gen;
  std::mt19937 engine(seed_gen);
  std::shuffle(cells.begin(), cells.end(), engin); 

  //マスの周りにあるMの数をカウント
  int pos;
  for(auto c : cells){
    if(c.hasM()){
      for(int x = std::max(0, posToX - 1); x < std::min(width, posToX + 1; x++){
        for(int y = std::max(0, posToY - 1); y < std::min(width, posToY + 1; y++){
          if(int p = xyToPos(x,y) != pos) cells.at(p).incrementMCount();
        }
      }
    }
    pos++;
  }
  
}

bool openCell(int pos){
  if(pos < 0 || cells.size() < pos) return false;

  if(cells.at(pos).open()){
    if(cells.at(pos).getAroundMNum() == 0){
      //明らかにMがないマスを自動で開く
      for(int x = std::max(0, posToX - 1); x < std::min(width, posToX + 1; x++){
        for(int y = std::max(0, posToY - 1); y < std::min(width, posToY + 1; y++){
          if(int p = xyToPos(x,y) != pos) openCell(p);
        }
      }
    }
  }else return false;

  return true;
}

bool isMOpened(){
  for(auto c : cells){
    if(c.hasM() && c.isOpened())return true;
  }
  return false;
}

bool isAllCellOpened(){
  for(auto c : cells){
    if(!c.isOpened() && !c.hasM()) return false; 
  }
  return true;
}
