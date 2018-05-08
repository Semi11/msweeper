#include "ms_board.hpp"
#include <random>
#include <algorithm>
#include <iostream>

Board::Board(int height, int width, int MNum):cells(height* width),height(height),width(width){
  //指定個数分Mをセット
  MNum = std::min(static_cast<int>(cells.size()),MNum);
  
  for(int i = 0;i < MNum;i++) cells.at(i).setM();

  //ボードをシャッフル
  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());
  std::shuffle(cells.begin(), cells.end(), engine); 

  //マスの周りにあるMの数をカウント
  int pos = 0;
  for(auto c : cells){
    if(c.hasM()){
      for(int y = std::max(0, posToY(pos, width) - 1); y <= std::min(height-1, posToY(pos, width) + 1); y++){
        for(int x = std::max(0, posToX(pos, width) - 1); x <= std::min(width-1, posToX(pos, width) + 1); x++){
          if((xyToPos(x,y,width)) != pos) cells.at(xyToPos(x,y,width)).incrementMCount();
        }
      }
    }
    pos++;
  }
}

bool Board::openCell(int pos){
  if(pos < 0 || static_cast<int>(cells.size()) <= pos) return false;

  if(cells.at(pos).open()){
    //明らかにMがないマスを自動で開く
    if(cells.at(pos).getAroundMNum() == 0){
      for(int y = std::max(0, posToY(pos, width) - 1); y <= std::min(height-1, posToY(pos, width) + 1); y++){
        for(int x = std::max(0, posToX(pos, width) - 1); x <= std::min(width-1, posToX(pos, width) + 1); x++){
          if(xyToPos(x,y,width) != pos) openCell(xyToPos(x,y,width));
        }
      }
    }
  }else return false;

  return true;
}

bool Board::openCell(int x, int y){
  return openCell(xyToPos(x,y,width)); 
}

bool Board::isMOpened(){
  for(auto c : cells){
    if(c.hasM() && c.isOpened())return true;
  }
  return false;
}

bool Board::isAllCellOpened(){
  for(auto c : cells){
    if(!c.isOpened() && !c.hasM()) return false; 
  }
  return true;
}

std::vector<CellState> Board::getAllCellState(){
  int size = static_cast<int>(cells.size());
  std::vector<CellState> cellsState(size);

  for(int i=0;i<size;i++){
      cellsState.at(i) = cells.at(i).getState();
  }
  
  return cellsState;
}
