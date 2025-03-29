#include "GameFacade.h"
#include <iostream>

void GameFacade::ProcessInput() {
    if(!gameOver && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

        Vector2 mousePos = GetMousePosition();
        Vector2 boardPos = {
            static_cast<float>(int(mousePos.x )/ 100), 
            static_cast<float>(int(mousePos.y )/ 100)  
        };

        if(selectedPosition.x == -1) { 

            Piece* piece = board.GetPiece(boardPos);
            if(piece !=nullptr && piece->GetColor() == currentPlayer) selectedPosition = boardPos;
            
        }

        else {
            Piece* selected = board.GetPiece(selectedPosition);
            
           Vector2 DefaultKingPos={-1,-1};

            if(selected->validateMove(board, selectedPosition, boardPos)) {

                Board tempBoard = board;
                tempBoard.MovePiece(selectedPosition,boardPos);
                
                if (!IsKingInCheck(tempBoard, (selected->GetType() == PieceType::KING) ? boardPos : DefaultKingPos)) {

                    board.MovePiece(selectedPosition, boardPos);
                    if (selected->GetType() == PieceType::KING) {
                        
                        if (currentPlayer == COLOUR::W) WhiteKing = boardPos;
                        else BlackKing = boardPos;
                        
                    }
                    currentPlayer = (currentPlayer == COLOUR::W) ? COLOUR::B : COLOUR::W;

                    if (IsCheckmate()) gameOver = true;
                    
                }else std::cout << "Illegal Move!!\n";

            }else std::cout << "Invalid move!" << std::endl;
            
            selectedPosition = {-1, -1}; // Deselect
        }
        
    }
}

bool GameFacade::IsKingInCheck(Board& TestBoard, Vector2 TempKingPos) {

    Vector2 kingPos=(currentPlayer == COLOUR::W) ? WhiteKing : BlackKing;

    if (TempKingPos.x !=-1.0 && TempKingPos.y !=-1.0 ) kingPos=TempKingPos;

    for (int y = 0; y < 8; y++) 
        for (int x = 0; x < 8; x++) {
            Vector2 pos = {static_cast<float>(x), static_cast<float>(y)};
            Piece* piece = TestBoard.GetPiece(pos);

            if (!piece || piece->GetColor() == currentPlayer) continue;

            if (piece->validateMove(TestBoard, pos, kingPos)) return true;
            
        }

    return false;
}

bool GameFacade::IsCheckmate() {

    Vector2 DefaultKingPos={-1,-1};
    if (!IsKingInCheck(board,DefaultKingPos)) return false;
    
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            Vector2 from = {static_cast<float>(x), static_cast<float>(y)};
            Piece* piece = board.GetPiece(from);

            if (!piece || piece->GetColor() != currentPlayer) continue; 

            for (int ty = 0; ty < 8; ty++) {
                for (int tx = 0; tx < 8; tx++) {
                    Vector2 to = {static_cast<float>(tx), static_cast<float>(ty)};

                    if (piece->validateMove(board, from, to)) {
                        
                        Board tempBoard = board;
                        tempBoard.MovePiece(from, to);

                        if (!IsKingInCheck(tempBoard,(piece->GetType() == PieceType::KING) ? to : DefaultKingPos)) 
                            return false;
                            
                    }
                }
            }
        }
    }
    return true; // No legal move found
}

void GameFacade::Render() const {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    board.Draw();
    
    if(selectedPosition.x != -1)
        DrawRectangleLines(selectedPosition.x*100+10, selectedPosition.y*100+10, 80, 80, YELLOW);
    
    if (gameOver) {
        DrawRectangle(100, 200, 600, 200, Fade(BLACK, 0.8f)); //Black overlay
        std::string message = (currentPlayer == COLOUR::W) ? "Black Wins! Checkmate!" : "White Wins! Checkmate!";
        DrawText(message.c_str(), 200, 270, 40, RAYWHITE);
    }

    EndDrawing();
}

GameFacade::GameFacade() : selectedPosition{-1, -1}, BlackKing{4, 7}, WhiteKing{4, 0} {}
