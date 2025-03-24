#ifndef PIECE_H
#define PIECE_H

#include <memory>
#include <raylib.h>

enum class PieceType { ROOK };
enum class COLOUR    { W, B };

class Piece {
public:
    virtual ~Piece() = default;
    virtual void Draw(Vector2 position) const = 0;
    virtual PieceType GetType() const = 0;
    virtual COLOUR GetColor() const = 0;

    static std::unique_ptr<Piece> PieceFactory(PieceType type, COLOUR color);

};

#endif