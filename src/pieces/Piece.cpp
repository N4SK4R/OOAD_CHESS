#include "Rook.cpp"
#include "Knight.cpp"
#include "Bishop.cpp"
#include "Queen.cpp"
#include "King.cpp"
#include "Pawn.cpp"

BasePiece::BasePiece(COLOUR c, const std::string& texturecolor_path, std::shared_ptr<MovementStrategy> strategy)
    : color(c), movementStrategy(strategy), theme(texturecolor_path[15])
    {texture = LoadTexture(texturecolor_path.c_str());}

BasePiece::BasePiece(const BasePiece& other) 
    : color(other.color), movementStrategy(other.movementStrategy), ownsTexture(false) {}

void BasePiece::Draw(Vector2 position) const {

        float scale = (theme==49) ? 0.36 : 4;
        DrawTextureEx(texture, position, 0.0f, scale, WHITE);
    }

bool BasePiece::validateMove(Board& board, Vector2 from, Vector2 to) {
        return movementStrategy->ValidateMove(board, color, from, to);
    }

BasePiece::~BasePiece() { if(ownsTexture)UnloadTexture(texture);}

std::unique_ptr<Piece> Piece::PieceFactory(PieceType type, COLOUR color, std::shared_ptr<MovementStrategy> sharedStrategy, int theme) {
    
    std::string color_path = (color == COLOUR::W ? "w" : "b");
    std::string path ="assets/textures"+ std::to_string(theme) +"/" + color_path;

    switch(type) {
        case PieceType::ROOK: 
            return std::make_unique<Rook>(color, path + "r.png", sharedStrategy);
        case PieceType::KNIGHT: 
            return std::make_unique<Knight>(color, path + "n.png", sharedStrategy);
        case PieceType::BISHOP: 
            return std::make_unique<Bishop>(color, path + "b.png", sharedStrategy);
        case PieceType::QUEEN: 
            return std::make_unique<Queen>(color, path + "q.png", sharedStrategy);
        case PieceType::KING: 
            return std::make_unique<King>(color, path + "k.png", sharedStrategy);
        case PieceType::PAWN: 
            return std::make_unique<Pawn>(color, path + "p.png", sharedStrategy);
        default: 
            return nullptr;
    }
    
}