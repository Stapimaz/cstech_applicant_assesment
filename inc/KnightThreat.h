//
// Created by Korhan on 5.06.2024.
//

#ifndef CSTECH_KNIGHTTHREAT_H
#define CSTECH_KNIGHTTHREAT_H

#include "ThreatChecker.h"

class KnightThreat : public ThreatChecker {
public:
    bool isThreat(int row, int col, const Board &currentBoard) const override {
        std::string possibleThreatPiece;  // mevcut taşın rengine bakılarak rakip as mi ab mi belirleniyor

        if (currentPieceColor(row, col, currentBoard) == 'b')
            possibleThreatPiece = "as";
        else if (currentPieceColor(row, col, currentBoard) == 's')
            possibleThreatPiece = "ab";

        int knightMoves[8][2] = {// atın yapabileceği tüm hareketler
                {-2, -1}, {-1, -2}, {1, -2}, {2, -1},
                {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};

        for (int i = 0; i < BOARD_SIZE; ++i) {  // atın tehdit oluşturabileceği tüm konumlar kontrol ediliyor
            int newrow = row + knightMoves[i][0];
            int newcol = col + knightMoves[i][1];
            if (newrow >= 0 && newrow < 8 && newcol >= 0 &&
                newcol < 8) {  // tahta sınırlarının aşılmadığı da dikkate alınıyor
                if (currentBoard.board[newrow][newcol] == possibleThreatPiece) {
                    return true;
                }
            }
        }
        return false;
    }
};

#endif  // CSTECH_KNIGHTTHREAT_H