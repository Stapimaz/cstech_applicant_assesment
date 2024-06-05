//
// Created by Korhan on 5.06.2024.
//

#ifndef CSTECH_BOARD_H
#define CSTECH_BOARD_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

const int BOARD_SIZE = 8;

class Board {
private:
public:
    std::string board[BOARD_SIZE][BOARD_SIZE];

    void importBoard(const std::string &filename) {
        std::ifstream file(filename);  // mainde belirtilen isimdeki .txt okunuyor
        std::string line;

        if (!file.is_open()) {  //öyle bir dosya yoksa uyarı veriyor
            std::cerr << filename << "'in  .exe ile aynı konumda olduğunu kontrol edin "
                      << "\n";
            return;
        }

        for (int i = 0; i < BOARD_SIZE; ++i) {
            if (std::getline(file, line)) {  // dosyadan satır alıyor
                int col = 0;
                for (int j = 0; j < 22;
                     j += 3) {  // .txt'deki boşlukları atlayarak sadece bitişik şekilde taşların yazdığı bir matris oluşturuyor
                    board[i][col++] = std::string(1, line[j]) + std::string(1, line[j + 1]);
                }
            } else {
                std::cerr << "getline hatası\n";
                break;
            }
        }
        file.close();
    }

    void printBoard() const {  // açılan dosyayı print ediyor, kontrol amaçlı
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

#endif  // CSTECH_BOARD_H
