#include "MovementStrategy.h"

class Knight : public Piece {
    COLOUR color;
    Texture2D texture;
    std::shared_ptr<MovementStrategy> moveValidator;
public:
    Knight(COLOUR c, const std::string& texturePath,std::shared_ptr<MovementStrategy> validator) : color(c), moveValidator(validator) {

        texture = LoadTexture(texturePath.c_str());
    }
    PieceType GetType() const override { return PieceType::KNIGHT; }
    COLOUR GetColor() const override { return color; }

    void Draw(Vector2 position) const override {
        float scale = 0.35f; 
        DrawTextureEx(texture, position, 0.0f, scale, WHITE);
    }

    virtual bool validateMove(Board& board,Vector2 from, Vector2 to) override{
        return moveValidator->ValidateMove(board,color ,from, to);
    }

    ~Knight() {

        UnloadTexture(texture);
    }
};