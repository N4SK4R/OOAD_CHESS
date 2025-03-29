#ifndef BOARD_H
#define BOARD_H

#include <array>
#include <memory>
#include <raylib.h>

class Piece; // Forward declaration instead of including Piece.h


class Board {
    static const int BOARD_SIZE = 8;
    std::array<std::array<std::unique_ptr<Piece>, BOARD_SIZE>, BOARD_SIZE> squares;

public:
    Board();
    Board(const Board& CurrentBoard);
    void Initialize();
    void MovePiece(Vector2 from, Vector2 to);
    Piece* GetPiece(Vector2 position) const;
    void Draw() const;
};

#endif