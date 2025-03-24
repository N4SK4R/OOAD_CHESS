#include "MovementStrategy.h"

class Bishop : public BasePiece {
    public:
        Bishop(COLOUR c, const std::string& texturePath, std::shared_ptr<MovementStrategy> strategy)
        : BasePiece(c, texturePath, strategy) {}
    
        PieceType GetType() const override { return PieceType::BISHOP; }
        COLOUR GetColor() const override { return color; }
    };
