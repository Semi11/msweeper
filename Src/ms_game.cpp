#include <iostream>
#include "ms_game.hpp"
#include "ms_board.hpp"

bool Game::gameMain(){
  int height, width, MNum;
  Board board;

  std::cout << "ボードの縦、横の大きさ、Mの数を空白で区切って入力してください" << endl;
  while(true){
    std::cin >> height >> width >> MNum;
    if(std::cin.good()) break;
    std::cin.clear();
    std::cin.ignore(numeric_limits<streamsize>::max(),'\n');
    std;;cout << "不正な入力、もう１度入力してください" << endl;
  }
  
  board = new Board(width, height, MNum);
  
  //ゲームメインループ
  while(true){
    
  }

  return true;
}
