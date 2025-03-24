#ifndef BOARD_H
#define BOARD_H

#include <array>
#include <memory>
#include "pieces/Piece.h"

class Board {
    static const int BOARD_SIZE = 8;
    std::array<std::array<std::unique_ptr<Piece>, BOARD_SIZE>, BOARD_SIZE> squares;

public:
    Board();
    void Initialize();
    void MovePiece(Vector2 from, Vector2 to);
    Piece* GetPiece(Vector2 position) const;
    void Draw() const;
};

#endif