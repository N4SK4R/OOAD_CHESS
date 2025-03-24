#ifndef ROOK_MOVEMENT_H
#define ROOK_MOVEMENT_H

#include "../MovementStrategy.h"
#include "../Board.h"

class RookMovement : public MovementStrategy {
public:
    bool ValidateMove(const Board& board, 
                    COLOUR playerColor,
                    Vector2 from, 
                    Vector2 to) const override;
};

#endif