#include "MovementStrategy.h"

class King : public BasePiece {
    public:
        King(COLOUR c, const std::string& texturePath, std::shared_ptr<MovementStrategy> strategy)
        : BasePiece(c, texturePath, strategy) {}
    
        PieceType GetType() const override { return PieceType::KING; }
        COLOUR GetColor() const override { return color; }
    };
