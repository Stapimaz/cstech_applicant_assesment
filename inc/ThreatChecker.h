//
// Created by Korhan on 5.06.2024.
//

#ifndef CSTECH_THREATCHECKER_H
#define CSTECH_THREATCHECKER_H

#include "current_color_check.h"

class ThreatChecker {  // tehdit kontrol için main class
public:
    virtual bool isThreat(int row, int col, const Board &currentBoard) const = 0;
    virtual ~ThreatChecker() = default;
};

#endif  // CSTECH_THREATCHECKER_H
