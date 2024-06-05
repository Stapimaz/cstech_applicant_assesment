//
// Created by Korhan on 5.06.2024.
//

#ifndef CSTECH_QUEENTHREAT_H
#define CSTECH_QUEENTHREAT_H

#include "ThreatChecker.h"

class QueenThreat : public ThreatChecker {
public:
    bool isThreat(int row, int col, const Board &currentBoard) const override {
        std::string possibleThreatPiece;  // mevcut taşın son rengine göre rakip vs mi vb mi belirleniyor

        if (currentPieceColor(row, col, currentBoard) == 'b')
            possibleThreatPiece = "vs";
        else if (currentPieceColor(row, col, currentBoard) == 's')
            possibleThreatPiece = "vb";

        // mevcut taşın sağına bakılıyor
        for (int i = col + 1; i < BOARD_SIZE; ++i) {
            if (currentBoard.board[row][i] == possibleThreatPiece) {
                return true;
            } else if (currentBoard.board[row][i] != "--") {
                break;  // vezirin yolunu kesen başka taş varsa tehdit edemez, break
            }
        }

        // mevcudun soluna bakılıyor
        for (int i = col - 1; i >= 0; --i) {
            if (currentBoard.board[row][i] == possibleThreatPiece) {
                return true;
            } else if (currentBoard.board[row][i] != "--") {
                break;
            }
        }

        // yukarı bakılıyor
        for (int i = row - 1; i >= 0; --i) {
            if (currentBoard.board[i][col] == possibleThreatPiece) {
                return true;
            } else if (currentBoard.board[i][col] != "--") {
                break;
            }
        }

        // aşağı bakılıyor
        for (int i = row + 1; i < BOARD_SIZE; ++i) {
            if (currentBoard.board[i][col] == possibleThreatPiece) {
                return true;
            } else if (currentBoard.board[i][col] != "--") {
                break;
            }
        }

        // sağ üst çapraz
        for (int i = 1; row - i >= 0 && col + i < BOARD_SIZE; ++i) {
            if (currentBoard.board[row - i][col + i] == possibleThreatPiece) {
                return true;
            } else if (currentBoard.board[row - i][col + i] != "--") {
                break;
            }
        }

        // sol üst çapraz
        for (int i = 1; row - i >= 0 && col - i >= 0; ++i) {
            if (currentBoard.board[row - i][col - i] == possibleThreatPiece) {
                return true;
            } else if (currentBoard.board[row - i][col - i] != "--") {
                break;
            }
        }

        // sağ alt çapraz
        for (int i = 1; row + i < BOARD_SIZE && col + i < BOARD_SIZE; ++i) {
            if (currentBoard.board[row + i][col + i] == possibleThreatPiece) {
                return true;
            } else if (currentBoard.board[row + i][col + i] != "--") {
                break;
            }
        }

        // sol alt çapraz
        for (int i = 1; row + i < BOARD_SIZE && col - i >= 0; ++i) {
            if (currentBoard.board[row + i][col - i] == possibleThreatPiece) {
                return true;
            } else if (currentBoard.board[row + i][col - i] != "--") {
                break;
            }
        }
        return false;  // tehdit yoksa
    }
};

#endif  // CSTECH_QUEENTHREAT_H
