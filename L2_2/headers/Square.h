#include "Figure.h"

class Square : public Figure
{
public:
    Square(Point point_a, Point point_b);

    static bool isIntersect(Square *fig1, Square *fig2);

    static Square *IntersectArea(Square *fig1, Square *fig2);

    ~Square();

private:
    Square();
};
