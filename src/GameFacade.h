#ifndef GAME_FACADE_H
#define GAME_FACADE_H

#include <raylib.h>
#include "pieces/Piece.h"

class GameFacade {
    
    Board board;
    Vector2 selectedPiece = {-1, -1};
   
public:

    void ProcessInput();
    void Render() const;
    void ShowPromotionMenu();
};

#endif