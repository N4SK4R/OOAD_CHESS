#ifndef GAME_H
#define GAME_H

#include <raylib.h>
#include "pieces/Piece.h"

class Game {
    
    Board board;
    Vector2 selectedPosition;
    Vector2 BlackKing;
    Vector2 WhiteKing;
    COLOUR currentPlayer = COLOUR::W;
    bool gameOver = false;
   
public:

    Game(int theme);
    void ProcessInput();
    void Render() const;
    bool IsKingInCheck(Board& TestBoard, Vector2 TempKingPos);
    bool IsCheckmate();
};

#endif