#ifndef GAME_FACADE_H
#define GAME_FACADE_H

#include <raylib.h>
#include "pieces/Piece.h"

class GameFacade {
    
    Board board;
    Vector2 selectedPosition;
    Vector2 BlackKing;
    Vector2 WhiteKing;
    COLOUR currentPlayer = COLOUR::W;
    bool gameOver = false;
   
public:

    GameFacade();
    void ProcessInput();
    void Render() const;
    bool IsKingInCheck(Board& TestBoard, Vector2 TempKingPos);
    bool IsCheckmate();
};

#endif