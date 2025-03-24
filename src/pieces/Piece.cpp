#include "Rook.cpp"
#include "Knight.cpp"

BasePiece::BasePiece(COLOUR c, const std::string& texturePath, std::shared_ptr<MovementStrategy> strategy)
    : color(c), movementStrategy(strategy) 
    {texture = LoadTexture(texturePath.c_str());}

void BasePiece::Draw(Vector2 position) const {
        float scale = 0.35f;
        DrawTextureEx(texture, position, 0.0f, scale, WHITE);
    }

bool BasePiece::validateMove(Board& board, Vector2 from, Vector2 to) {
        return movementStrategy->ValidateMove(board, color, from, to);
    }

BasePiece::~BasePiece() { UnloadTexture(texture); }

std::unique_ptr<Piece> Piece::PieceFactory(PieceType type, COLOUR color, std::shared_ptr<MovementStrategy> sharedStrategy) {
    switch(type) {
        case PieceType::ROOK: 
            return color == COLOUR::W ? std::make_unique<Rook>(color, "assets/textures/wr.png", sharedStrategy) : std::make_unique<Rook>(color, "assets/textures/br.png",sharedStrategy); 
        case PieceType::KNIGHT: 
            return color == COLOUR::W ? std::make_unique<Knight>(color, "assets/textures/wn.png", sharedStrategy) : std::make_unique<Knight>(color, "assets/textures/bn.png",sharedStrategy);
        default: return nullptr;
    }
}