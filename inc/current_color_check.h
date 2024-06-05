//
// Created by Korhan on 5.06.2024.
//

#ifndef CSTECH_CURRENT_COLOR_CHECK_H
#define CSTECH_CURRENT_COLOR_CHECK_H

#include "Board.h"

char currentPieceColor(int row, int col, const Board &currentBoard) {
    std::string piece = currentBoard.board[row][col];  // mevcut taşın ikinci hanesine bakar rengini
    return piece[1];                                       // tespit ediyor
}

#endif  // CSTECH_CURRENT_COLOR_CHECK_H
