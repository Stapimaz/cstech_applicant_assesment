#include <string>

#include "Board.h"
#include "Score.h"

int main() {
    Board board;
    std::string filename = "board1.txt";  // AÇILMASI İSTENİLEN .txt'nin İSMİ GİRİLİR
    board.importBoard(filename);
    board.printBoard();

    Score score;
    std::string outputfilename = "sonuclar.txt";  // SONUÇLARIN YAZILACAĞI .txt'nin İSMİ GİRİLİR
    score.printScore(board, outputfilename, filename);

    return 0;
}
