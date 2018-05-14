//game.cpp
#include <iostream>
#include <limits>
#include "ms_game.hpp"
#include "ms_board.hpp"
#include "ms_view.hpp"

bool Game::gameMain(){
  int height, width, MNum;
  View view;

  std::cout << "ボードの縦の大きさを入力してください" << std::endl;
  height = inputNum();
  std::cout << "ボードの横の大きさを入力してください" << std::endl;
  width = inputNum();
  std::cout << "Mの数を入力してください" << std::endl;
  MNum = inputNum();

  Board board(height, width, MNum);
  view.dispBoard(board.getAllCellState(), height, width);

  time = clock();
  //ゲームメインループ
  while(true){
    if(board.isMOpened()) {
      std::cout << "GameOver" << std::endl;
      break;
    }
    
    if(board.isAllCellOpened()) {
      std::cout << "GameClear" << std::endl;
      std::cout << "Clear Time " << clock() - time << std::endl; 
      break;
    }
    
    while(true){
      int x,y;
      std::cout << "開きたいマスの座標を入力してください" << std::endl;
      std::cout << "x->";
      x = inputNum();
      std::cout << "y->";
      y = inputNum();
      if(board.openCell(x,y))break;
      std::cout << "そのマスは開けません" << std::endl << "もう一度入力してください" << std::endl;
    }
    view.dispBoard(board.getAllCellState(), height, width);
    
  }
  return true;
}

int Game::inputNum(){
  int num;

  while(true){
    std::cin >> num;
    if(std::cin.good() && num >= 0 && num <=100) return num;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << "不正な入力、もう１度入力してください(0-100)" << std::endl;
  }
}
