#include <iostream>
#include <limits>
#include "ms_game.hpp"
#include "ms_board.hpp"

bool Game::gameMain(){
  int height, width, MNum;

  std::cout << "ボードの縦の大きさを入力してください" << std::endl;
  height = inputNum();
  std::cout << "ボードの横の大きさを入力してください" << std::endl;
  width = inputNum();
  std::cout << "Mの数を入力してください" << std::endl;
  MNum = inputNum();
  
  Board board(width, height, MNum);
  
  //ゲームメインループ
  while(true){
    std::cout << "開きたいマスの数値を入力してください" << std::endl;
    board.openCell(inputNum());

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
