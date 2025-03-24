#include "pieces/RookMovement.h"

Board::Board() { Initialize(); }

void Board::Initialize() {

    std::shared_ptr<MovementStrategy> RookStrategy=std::make_shared<RookMovement>();

    squares[0][0] = Piece::PieceFactory(PieceType::ROOK, COLOUR::W, RookStrategy);
    squares[0][7] = Piece::PieceFactory(PieceType::ROOK, COLOUR::W, RookStrategy);
    squares[7][0] = Piece::PieceFactory(PieceType::ROOK, COLOUR::B, RookStrategy);
    squares[7][7] = Piece::PieceFactory(PieceType::ROOK, COLOUR::B, RookStrategy);
}

void Board::MovePiece(Vector2 from, Vector2 to) {
    squares[to.y][to.x] = std::move(squares[from.y][from.x]);
}

Piece* Board::GetPiece(Vector2 position) const {
    return squares[position.y][position.x].get();
}

void Board::Draw() const {
    for(int y = 0; y < BOARD_SIZE; y++) {
        for(int x = 0; x < BOARD_SIZE; x++) {
            Color squareColor = (x + y) % 2 == 0 ? Color{240, 217, 181, 255} : Color{181, 136, 99, 255};
            DrawRectangle(x*100, y*100, 100, 100, squareColor);
            
            if(squares[y][x]!=nullptr) {
                Vector2 pos = {static_cast<float>(x*100), static_cast<float>(y*100)};
                squares[y][x]->Draw(pos);
            }
        }
    }
}