#include <iostream>
#include <limits>
#include "ms_game.hpp"
#include "ms_board.hpp"
#include "ms_view.hpp"

bool Game::gameMain(){
  int height, width, MNum;
<<<<<<< HEAD
  View view;
=======
>>>>>>> e5575f398f5db9fae182f873c7718d6757755d20

  std::cout << "ボードの縦の大きさを入力してください" << std::endl;
  height = inputNum();
  std::cout << "ボードの横の大きさを入力してください" << std::endl;
  width = inputNum();
  std::cout << "Mの数を入力してください" << std::endl;
  MNum = inputNum();
<<<<<<< HEAD

  Board board(height, width, MNum);
  view.dispBoard(board.getAllCellState(), height, width);

  time = clock();
  //ゲームメインループ
  while(true){
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
    
=======
  
  Board board(width, height, MNum);
  
  //ゲームメインループ
  while(true){
    std::cout << "開きたいマスの数値を入力してください" << std::endl;
    board.openCell(inputNum());

>>>>>>> e5575f398f5db9fae182f873c7718d6757755d20
    if(board.isMOpened()) {
      std::cout << "GameOver" << std::endl;
      break;
    }
    
    if(board.isAllCellOpened()) {
      std::cout << "GameClear" << std::endl;
<<<<<<< HEAD
      std::cout << "Clear Time " << clock() - time << std::endl; 
      break;
    }
=======
      break;
    }

>>>>>>> e5575f398f5db9fae182f873c7718d6757755d20
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
