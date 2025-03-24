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
                if(piece !=nullptr && piece->GetType() == PieceType::ROOK) {
                    selectedPiece = boardPos;
                    std::cout << "Selected rook at (" << selectedPiece.x << ", " << selectedPiece.y << ")" << std::endl;
                }
            }

            else {
                Piece* selected = board.GetPiece(selectedPiece);


                if(rookMovement.ValidateMove(board, selected->GetColor(), selectedPiece, boardPos)) {
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
    
    if(selectedPiece.x != -1) {
        DrawRectangleLines(selectedPiece.x*100+10, selectedPiece.y*100+10, 80, 80, YELLOW);
    }
    
    EndDrawing();
}