#ifndef MOVEMENT_STRATEGY_H
#define MOVEMENT_STRATEGY_H

#include "Piece.h"

class Board;

class MovementStrategy {
public:
    virtual ~MovementStrategy() = default;
    virtual bool ValidateMove(const Board& board, COLOUR playerColor,Vector2 from, Vector2 to) const = 0;
};

class RookMovement : public MovementStrategy {
    public:
        bool ValidateMove(const Board& board, COLOUR playerColor,Vector2 from, Vector2 to) const override;
};

class KnightMovement : public MovementStrategy {
    public:
        bool ValidateMove(const Board& board, COLOUR playerColor,Vector2 from, Vector2 to) const override;
};

class BishopMovement : public MovementStrategy {
    public:
        bool ValidateMove(const Board& board, COLOUR playerColor,Vector2 from, Vector2 to) const override;
};

class QueenMovement : public MovementStrategy {
    public:
        bool ValidateMove(const Board& board, COLOUR playerColor, Vector2 from, Vector2 to) const override;
};

class KingMovement : public MovementStrategy {
    public:
        bool ValidateMove(const Board& board, COLOUR playerColor, Vector2 from, Vector2 to) const override;
};

class PawnMovement : public MovementStrategy {
    public:
        bool ValidateMove(const Board& board, COLOUR playerColor, Vector2 from, Vector2 to) const override;
};

#endif 