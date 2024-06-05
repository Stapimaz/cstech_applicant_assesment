//
// Created by Korhan on 5.06.2024.
//

#ifndef CSTECH_PAWNTHREAT_H
#define CSTECH_PAWNTHREAT_H

#include "ThreatChecker.h"

class PawnThreat : public ThreatChecker {
public:
    bool isThreat(int row, int col, const Board &currentBoard) const override {
        std::string possibleThreatPiece;  // rakip piyon ps mi pb mi, mevcut piyonun son harfine bakılarak bulunuyor

        if (currentPieceColor(row, col, currentBoard) == 'b')
            possibleThreatPiece = "ps";
        else if (currentPieceColor(row, col, currentBoard) == 's')
            possibleThreatPiece = "pb";

        if (possibleThreatPiece == "ps") {  // Rakip ps ise yukarı çaprazlardan saldırabilir, kontrol ediliyor
            if (row - 1 >= 0 && col - 1 >= 0 && currentBoard.board[row - 1][col - 1] == "ps")
                return true;
            else if ((row - 1 >= 0 && col + 1 < BOARD_SIZE) && currentBoard.board[row - 1][col + 1] == "ps")
                return true;
            else
                return false;
        }

        else if (possibleThreatPiece == "pb") {  // Rakip pb ise aşağı çaprazlardan saldırabilir, kontrol ediliyor
            if (row + 1 < BOARD_SIZE && col - 1 >= 0 && currentBoard.board[row + 1][col - 1] == "pb") {
                return true;
            } else if (row + 1 < BOARD_SIZE && col + 1 < BOARD_SIZE && currentBoard.board[row + 1][col + 1] == "pb")
                return true;
            else
                return false;
        } else
            return false;
    }
};

#endif  // CSTECH_PAWNTHREAT_H