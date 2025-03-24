#include "GameFacade.h"
#include <iostream>

void GameFacade::ProcessInput() {
    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePos = GetMousePosition();
        Vector2 boardPos = {
            static_cast<float>(int(mousePos.x )/ 100), 
            static_cast<float>(int(mousePos.y )/ 100)  
        };

        std::cout << "Mouse position: (" << mousePos.x << ", " << mousePos.y << ") -> "
                  << "Board position: (" << boardPos.x << ", " << boardPos.y << ")" << std::endl;

        if(boardPos.x >= 0 && boardPos.x < 8 && boardPos.y >= 0 && boardPos.y < 8) {

            if(selectedPiece.x == -1) { 

                Piece* piece = board.GetPiece(boardPos);
                if(piece !=nullptr) selectedPiece = boardPos;
                
            }

            else {
                Piece* selected = board.GetPiece(selectedPiece);

                if(selected->GetType()==PieceType::PAWN) {

                    int promotionRow = (selected->GetColor() == COLOUR::W) ? 7 : 0;
                    if(boardPos.y == promotionRow) std::cout << "Promotion!!\n";
                }
                
                if(selected->validateMove(board, selectedPiece, boardPos)) {
                    std::cout << "Valid move!" << std::endl;

                    board.MovePiece(selectedPiece, boardPos);   
                }
                else {
                    std::cout << "Invalid move!" << std::endl;
                }
                selectedPiece = {-1, -1}; // Deselect
            }
        }
    }
}

void GameFacade::Render() const {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    board.Draw();
    
    if(selectedPiece.x != -1)
        DrawRectangleLines(selectedPiece.x*100+10, selectedPiece.y*100+10, 80, 80, YELLOW);
    
    EndDrawing();
}

void GameFacade::ShowPromotionMenu() {

    DrawRectangle(350, 360, 100, 60, LIGHTGRAY);
    
}