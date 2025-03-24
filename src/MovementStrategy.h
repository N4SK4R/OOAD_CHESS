#ifndef MOVEMENT_STRATEGY_H
#define MOVEMENT_STRATEGY_H

#include "pieces/Piece.h"

class Board;

class MovementStrategy {
public:
    virtual ~MovementStrategy() = default;
    virtual bool ValidateMove(const Board& board, COLOUR playerColor,Vector2 from, Vector2 to) const = 0;
};

#endif 