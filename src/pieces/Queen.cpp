#include "MovementStrategy.h"

class Queen : public BasePiece {
    public:
        Queen(COLOUR c, const std::string& texturePath, std::shared_ptr<MovementStrategy> strategy)
        : BasePiece(c, texturePath, strategy) {}
    
        PieceType GetType() const override { return PieceType::QUEEN; }
        COLOUR GetColor() const override { return color; }

        std::unique_ptr<Piece> clone() const override{
            return std::make_unique<Queen>(*this);
        }
    };
