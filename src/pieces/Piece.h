#ifndef PIECE_H
#define PIECE_H

#include <memory>
#include <raylib.h>
#include "../Board.h"

class MovementStrategy;

enum class PieceType { ROOK, KNIGHT };
enum class COLOUR    { W, B };

class Piece {
public:
    virtual ~Piece() = default;
    virtual void Draw(Vector2 position) const = 0;
    virtual PieceType GetType() const = 0;
    virtual COLOUR GetColor() const = 0;
    virtual bool validateMove(Board& board,Vector2 from, Vector2 to) = 0;

    static std::unique_ptr<Piece> PieceFactory(PieceType type, COLOUR color, std::shared_ptr<MovementStrategy> sharedStrategy);

};

class BasePiece : public Piece {
    protected:
        COLOUR color;
        Texture2D texture;
        std::shared_ptr<MovementStrategy> movementStrategy;
    
    public:
        BasePiece(COLOUR c, const std::string& texturePath, std::shared_ptr<MovementStrategy> strategy);
        void Draw(Vector2 position) const override;
        bool validateMove(Board& board, Vector2 from, Vector2 to) override;
        ~BasePiece() override;
    };

#endif