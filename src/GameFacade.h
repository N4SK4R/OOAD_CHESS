#ifndef GAME_FACADE_H
#define GAME_FACADE_H

#include <raylib.h>
#include "Board.h"
#include "pieces/RookMovement.h"

class GameFacade {
    Board board;
    Vector2 selectedPiece = {-1, -1};
    RookMovement rookMovement;

public:
    void ProcessInput();
    void Render() const;
};

#endif