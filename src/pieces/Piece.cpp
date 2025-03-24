#include "Rook.cpp"
#include "Knight.cpp"

std::unique_ptr<Piece> Piece::PieceFactory(PieceType type, COLOUR color, std::shared_ptr<MovementStrategy> sharedStrategy) {
    switch(type) {
        case PieceType::ROOK: 
            return color == COLOUR::W ? std::make_unique<Rook>(color, "assets/textures/wr.png", sharedStrategy) : std::make_unique<Rook>(color, "assets/textures/br.png",sharedStrategy); 
        case PieceType::KNIGHT: 
            return color == COLOUR::W ? std::make_unique<Knight>(color, "assets/textures/wn.png", sharedStrategy) : std::make_unique<Knight>(color, "assets/textures/bn.png",sharedStrategy);
        default: return nullptr;
    }
}