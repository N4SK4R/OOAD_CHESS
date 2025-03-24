#include "Piece.h"

class Rook : public Piece {
    COLOUR color;
    Texture2D texture;
public:
    Rook(COLOUR c, const std::string& texturePath) : color(c) {

        texture = LoadTexture(texturePath.c_str());
    }
    PieceType GetType() const override { return PieceType::ROOK; }
    COLOUR GetColor() const override { return color; }

    void Draw(Vector2 position) const override {
        float scale = 0.35f; 
        DrawTextureEx(texture, position, 0.0f, scale, WHITE);
        //DrawTexture(texture, static_cast<int>(position.x), static_cast<int>(position.y), WHITE);
    }

    ~Rook() {

        UnloadTexture(texture);
    }
};

std::unique_ptr<Piece> Piece::PieceFactory(PieceType type, COLOUR color) {
    switch(type) {
        case PieceType::ROOK: 
            return color == COLOUR::W ? std::make_unique<Rook>(color, "assets/textures/wr.png") : std::make_unique<Rook>(color, "assets/textures/br.png"); 
        default: return nullptr;
    }
}