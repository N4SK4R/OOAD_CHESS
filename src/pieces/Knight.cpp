#include "MovementStrategy.h"

class Knight : public BasePiece {
    public:
        Knight(COLOUR c, const std::string& texturePath, std::shared_ptr<MovementStrategy> strategy)
        : BasePiece(c, texturePath, strategy) {}
    
        PieceType GetType() const override { return PieceType::KNIGHT; }
        COLOUR GetColor() const override { return color; }
    };
