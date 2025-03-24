#include "MovementStrategy.h"

class Rook : public BasePiece {
    public:
        Rook(COLOUR c, const std::string& texturePath, std::shared_ptr<MovementStrategy> strategy)
        : BasePiece(c, texturePath, strategy) {}
    
        PieceType GetType() const override { return PieceType::ROOK; }
        COLOUR GetColor() const override { return color; }
    };
