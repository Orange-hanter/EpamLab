#include "Figure.h"

Figure::Figure(double x, double y)
{
    points.push_back(Point{x, y});
    type = FigureType::POINT;
}

Figure::Figure(Point highPoint, Point lowPoint)
{
    points.push_back(highPoint);
    points.push_back(lowPoint);
    type = FigureType::SQUARE;
}

Figure::Figure(Point point_a, Point point_b, Point point_c)
{
    points.push_back(point_a);
    points.push_back(point_b);
    points.push_back(point_c);
    type = FigureType::TRIANGLE;
}

Figure::Figure(Point point, ...)
{
    //TODO: read how to work vith multiple arguments
    type = FigureType::POLYGON;
}

void Figure::moveFigure(double dX, double dY)
{
    for (auto point : points)
    {
        point.x += dX;
        point.y += dY;
    }
}