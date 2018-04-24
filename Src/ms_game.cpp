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

  //ゲームメインループ
  while(true){
    std::cout << "開きたいマスの数値を入力してください" << std::endl;
    while(!board.openCell(inputNum())){
      std::cout << "そのマスは開けません" << std::endl;
      std::cout << "もう一度入力してください" << std::endl;
    }

    view.dispBoard(board.getAllCellState(), height, width);
    
    if(board.isMOpened()) {
      std::cout << "GameOver" << std::endl;
      break;
    }
    
    if(board.isAllCellOpened()) {
      std::cout << "GameClear" << std::endl;
      break;
    }

  }

  return true;
}

int Game::inputNum(){
  int num;

  while(true){
    std::cin >> num;
    if(std::cin.good()) return num;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << "不正な入力、もう１度入力してください" << std::endl;
  }
}
