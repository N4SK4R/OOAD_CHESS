#include "RookMovement.h"
#include <cmath>

bool RookMovement::ValidateMove(const Board& board, COLOUR playerColor,Vector2 from, Vector2 to) const {
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