//
// Created by Korhan on 5.06.2024.
//

#ifndef CSTECH_SCORE_H
#define CSTECH_SCORE_H

#include "Board.h"
#include "Piece.h"

class Score {
private:
    double whiteScore{0};
    double blackScore{0};

    void calculateScore(
            const Board &currentBoard) {  // board matrisinde gezilerek her bir taşın final değeri
        // bulunuyor ve birikerek beyazın ve siyahın son skorları elde ediliyor
        for (int row = 0; row < BOARD_SIZE; ++row) {
            for (int col = 0; col < BOARD_SIZE; ++col) {
                Piece currentPiece;  // temsili bir taş oluşturuluyor, tüm tahtayı geziyor
                currentPiece.finalPieceValue(row, col, currentBoard);

                if (currentPieceColor(row, col, currentBoard) == 'b')  // taş beyaz ise
                    whiteScore += currentPiece.finalValue;  // mevcut taş değeri, toplam beyaz skoruna ekleniyor
                else if (currentPieceColor(row, col, currentBoard) == 's')  // taş siyah ise
                    blackScore += currentPiece.finalValue;  // mevcut taş değeri, toplam siyah skoruna ekleniyor
            }
        }
    }

public:
    void printScore(const Board &currentBoard, const std::string &outputfilename, const std::string &filename) {
        calculateScore(currentBoard);  // Calculate scores

        std::ofstream outputFile(outputfilename, std::ios::app);  //üstüne yazmasın diye dosyayı append mode'da açıyorum

        if (outputFile.is_open()) {
            std::ifstream inFile(outputfilename);
            bool isEmpty = (inFile.peek() == std::ifstream::traits_type::eof());
            inFile.close();

            // dosya boş mu diye kontrol ediyor, boşsa başlığı yazıyor
            if (isEmpty) {
                outputFile << "Tahta Dosya Adı\tSonuçlar\n";
            }

            // okunan board'ın sonuçlarını yazıyor
            outputFile << filename << "\t\tSiyah:" << blackScore << "\tBeyaz:" << whiteScore << std::endl;
            outputFile.close();
        }
    }
};

#endif  // CSTECH_SCORE_H
