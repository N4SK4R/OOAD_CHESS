#include "Piece.h"
#include "../MovementStrategy.h"

class Rook : public Piece {
    COLOUR color;
    Texture2D texture;
    std::shared_ptr<MovementStrategy> moveValidator;
public:
    Rook(COLOUR c, const std::string& texturePath,std::shared_ptr<MovementStrategy> validator) : color(c), moveValidator(validator) {

        texture = LoadTexture(texturePath.c_str());
    }
    PieceType GetType() const override { return PieceType::ROOK; }
    COLOUR GetColor() const override { return color; }

    void Draw(Vector2 position) const override {
        float scale = 0.35f; 
        DrawTextureEx(texture, position, 0.0f, scale, WHITE);
        //DrawTexture(texture, static_cast<int>(position.x), static_cast<int>(position.y), WHITE);
    }

    virtual bool validateMove(Board& board,Vector2 from, Vector2 to) override{
        return moveValidator->ValidateMove(board,color ,from, to);
    }

    ~Rook() {

        UnloadTexture(texture);
    }
};

std::unique_ptr<Piece> Piece::PieceFactory(PieceType type, COLOUR color, std::shared_ptr<MovementStrategy> sharedStrategy) {
    switch(type) {
        case PieceType::ROOK: 
            return color == COLOUR::W ? std::make_unique<Rook>(color, "assets/textures/wr.png", sharedStrategy) : std::make_unique<Rook>(color, "assets/textures/br.png",sharedStrategy); 
        default: return nullptr;
    }
}