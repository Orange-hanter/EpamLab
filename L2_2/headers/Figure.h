#include <vector>
#include "Line.h"

enum FigureType
{
    POINT = 0,
    SQUARE,
    RECTANGLE,
    PARALELOGRAMM,
    TRIANGLE,
    POLYGON
};

class Figure
{
public:
    Figure(double x = 0, double y = 0);

    Figure(Point highPoint, Point lowPoint);
    Figure(Point point_a, Point point_b, Point point_c);
    Figure(Point point, ...);

    void moveFigure(double dX, double dY);

protected:
    std::vector<Point> points;
    FigureType type;
};
