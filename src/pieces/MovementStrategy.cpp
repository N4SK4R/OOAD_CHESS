#include "MovementStrategy.h"
#include <cmath>

bool RookMovement::ValidateMove(Board& board, COLOUR playerColor,Vector2 from, Vector2 to) const {
    // Must move in straight line
    if(from.x != to.x && from.y != to.y) return false;

    // Check path is clear
    int dx = (to.x > from.x) ? 1 : (to.x < from.x) ? -1 : 0;
    int dy = (to.y > from.y) ? 1 : (to.y < from.y) ? -1 : 0;
    
    Vector2 current = {from.x + dx, from.y + dy};
    while(current.x != to.x || current.y != to.y) {
        if(board.GetPiece(current)) return false;
        current.x += dx;
        current.y += dy;
    }

    Piece* target = board.GetPiece(to);
    return !target || target->GetColor() != playerColor;
}

bool KnightMovement::ValidateMove(Board& board, COLOUR playerColor,Vector2 from, Vector2 to) const {
    // Calculate absolute differences
    int dx = abs(to.x - from.x);
    int dy = abs(to.y - from.y);

    // Knight moves in L-shape (2-1 or 1-2)
    if (!((dx == 2 && dy == 1) || (dx == 1 && dy == 2))) {
    return false;
    }

    // Knights can jump over pieces - only check destination
    Piece* target = board.GetPiece(to);
    return !target || target->GetColor() != playerColor;
}

bool BishopMovement::ValidateMove(Board& board, COLOUR playerColor,Vector2 from, Vector2 to) const {
    // Calculate absolute differences
    int dx = abs(to.x - from.x);
    int dy = abs(to.y - from.y);

    // Bishop must move diagonally (equal x and y difference)
    if (dx != dy) return false;

    // Check path is clear
    int stepX = (to.x > from.x) ? 1 : -1;
    int stepY = (to.y > from.y) ? 1 : -1;
    
    Vector2 current = {from.x + stepX, from.y + stepY};
    while (current.x != to.x || current.y != to.y) {
        if (board.GetPiece(current)) return false;
        current.x += stepX;
        current.y += stepY;
    }

    // Check destination
    Piece* target = board.GetPiece(to);
    return !target || target->GetColor() != playerColor;
}

bool QueenMovement::ValidateMove(Board& board, COLOUR playerColor,Vector2 from, Vector2 to) const {
    // Calculate movement differences
    int dx = abs(to.x - from.x);
    int dy = abs(to.y - from.y);

    // Queen must move straight or diagonally
    if (!(dx == dy || from.x == to.x || from.y == to.y)) {
        return false;
    }

    // Determine movement direction
    int stepX = (to.x > from.x) ? 1 : (to.x < from.x) ? -1 : 0;
    int stepY = (to.y > from.y) ? 1 : (to.y < from.y) ? -1 : 0;

    // Check path is clear (excluding start and destination)
    Vector2 current = {from.x + stepX, from.y + stepY};
    while (current.x != to.x || current.y != to.y) {
        if (board.GetPiece(current)) {
            return false; // Piece blocking the path
        }
        current.x += stepX;
        current.y += stepY;
    }

    // Check destination
    Piece* target = board.GetPiece(to);
    return !target || target->GetColor() != playerColor;
}

bool KingMovement::ValidateMove(Board& board, COLOUR playerColor,Vector2 from, Vector2 to) const {

    int dx = abs(to.x - from.x);
    int dy = abs(to.y - from.y);

    if (dx <= 1 && dy <= 1) {
        Piece* target = board.GetPiece(to);
        return !target || target->GetColor() != playerColor;
    }

    if (dy == 0 && dx == 2 && from.y == (playerColor == COLOUR::W ? 7 : 0)) {

        // Kingside castle
        if (to.x > from.x) {
            Vector2 rookPos =  {7, from.y};
            Vector2 between1 = {5, from.y};
            Vector2 between2 = {6, from.y};
            
            Piece* rook = board.GetPiece(rookPos);

            if (rook && rook->GetType() == PieceType::ROOK
            && !board.GetPiece(between1) && !board.GetPiece(between2))
            {
                board.MovePiece(rookPos, between1); 
                return true;
            }
             
        }

        // Queenside castle
        else if (to.x < from.x) {
            Vector2 rookPos =  {0, from.y};
            Vector2 between1 = {1, from.y};
            Vector2 between2 = {2, from.y};
            Vector2 between3 = {3, from.y};
            
            Piece* rook = board.GetPiece(rookPos);

            if (rook && rook->GetType() == PieceType::ROOK
            && !board.GetPiece(between1) && !board.GetPiece(between2) && !board.GetPiece(between3))
            {
                board.MovePiece(rookPos, between3); 
                return true;
            }
                   
        }
    }
    return false;
}

bool PawnMovement::ValidateMove(Board& board, COLOUR playerColor,Vector2 from, Vector2 to) const {

    int direction = (playerColor == COLOUR::W) ? -1 : 1;
    int startRow = (playerColor == COLOUR::W) ? 6 : 1;

    if (from.x == to.x) {
        
        if (to.y == from.y + direction) return !board.GetPiece(to); 
        
        // Double step from starting position
        else if (from.y == startRow && to.y == from.y + 2*direction) {
            Vector2 mid = {from.x, from.y + direction};
            return !board.GetPiece(mid) && !board.GetPiece(to);
        }
        return false;
    }

    // Capture (diagonal)
    else if (abs(to.x - from.x) == 1 && to.y == from.y + direction) {
        Piece* target = board.GetPiece(to);
        
        if (target && target->GetColor() != playerColor) {
            return true;
        }
    }

    return false;
}