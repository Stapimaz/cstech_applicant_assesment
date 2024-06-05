cmake_minimum_required(VERSION 3.28)
project(cstech)

set(CMAKE_CXX_STANDARD 17)

add_executable(cstech main.cpp
        Board.h
        QueenThreat.h
        PawnThreat.h
        current_color_check.h
        KnightThreat.h
        Piece.h
        Score.h
        ThreatChecker.h
)
