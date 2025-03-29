#include "pieces/MovementStrategy.h"

Board::Board(int theme) { Initialize(theme); }

void Board::Initialize(int theme) {
    
    std::shared_ptr<MovementStrategy> RookStrategy = std::make_shared<RookMovement>();
    std::shared_ptr<MovementStrategy> KnightStrategy = std::make_shared<KnightMovement>();
    std::shared_ptr<MovementStrategy> BishopStrategy = std::make_shared<BishopMovement>();
    std::shared_ptr<MovementStrategy> QueenStrategy = std::make_shared<QueenMovement>();
    std::shared_ptr<MovementStrategy> KingStrategy = std::make_shared<KingMovement>();
    std::shared_ptr<MovementStrategy> PawnStrategy = std::make_shared<PawnMovement>();

    // Black pieces 
    squares[0][0] = Piece::PieceFactory(PieceType::ROOK, COLOUR::B, RookStrategy, theme);
    squares[0][7] = Piece::PieceFactory(PieceType::ROOK, COLOUR::B, RookStrategy, theme);
    squares[0][1] = Piece::PieceFactory(PieceType::KNIGHT, COLOUR::B, KnightStrategy, theme);
    squares[0][6] = Piece::PieceFactory(PieceType::KNIGHT, COLOUR::B, KnightStrategy, theme);
    squares[0][2] = Piece::PieceFactory(PieceType::BISHOP, COLOUR::B, BishopStrategy, theme);
    squares[0][5] = Piece::PieceFactory(PieceType::BISHOP, COLOUR::B, BishopStrategy, theme);
    squares[0][3] = Piece::PieceFactory(PieceType::QUEEN, COLOUR::B, QueenStrategy, theme);
    squares[0][4] = Piece::PieceFactory(PieceType::KING, COLOUR::B, KingStrategy, theme);

    // Black pawns
    for (int i = 0; i < 8; i++) {
        squares[1][i] = Piece::PieceFactory(PieceType::PAWN, COLOUR::B, PawnStrategy, theme);
    }

    // White pieces
    squares[7][0] = Piece::PieceFactory(PieceType::ROOK, COLOUR::W, RookStrategy, theme);
    squares[7][7] = Piece::PieceFactory(PieceType::ROOK, COLOUR::W, RookStrategy, theme);
    squares[7][1] = Piece::PieceFactory(PieceType::KNIGHT, COLOUR::W, KnightStrategy, theme);
    squares[7][6] = Piece::PieceFactory(PieceType::KNIGHT, COLOUR::W, KnightStrategy, theme);
    squares[7][2] = Piece::PieceFactory(PieceType::BISHOP, COLOUR::W, BishopStrategy, theme);
    squares[7][5] = Piece::PieceFactory(PieceType::BISHOP, COLOUR::W, BishopStrategy, theme);
    squares[7][3] = Piece::PieceFactory(PieceType::QUEEN, COLOUR::W, QueenStrategy, theme);
    squares[7][4] = Piece::PieceFactory(PieceType::KING, COLOUR::W, KingStrategy, theme);

    // White pawns
    for (int i = 0; i < 8; i++) {
        squares[6][i] = Piece::PieceFactory(PieceType::PAWN, COLOUR::W, PawnStrategy, theme);
    }

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

Board::Board(const Board& CurrentBoard) { 
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (CurrentBoard.squares[i][j]) {
                squares[i][j] = CurrentBoard.squares[i][j]->clone();
            }
        }
    }
}