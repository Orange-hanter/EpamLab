#include "Line.h"

Line::Line(Point p1, Point p2)
{
    A = p1.y - p2.y;
    B = p1.x - p2.x;
    C = (p1.x - p2.x) * p1.y + (p1.y - p2.y)* p1.x;
}

Line::Line(Point point)
{
    Point zero{0,0};
    A = point.y - zero.y;
    B = point.x - zero.x;
    C = (point.x - zero.x) * point.y + (point.y - zero.y) * point.x;
}

bool Line::isIntersect(Line line){
    // y1 = Zx + C  - this Line
    // y2 = Fx + D  - line
    // Ax + C = Bx + D
    // the only wey when lines in intersect, it is the case F not equal Z
    double Z = A/(-B);
    double F = line.A/(-1 * line.B);

    if (Z == F)
        return false;
    else
        return true;
}

Point Line::pointIntersection(Line line){
    // y1 = Zx + P  - this Line
    // y2 = Fx + D  - line
    // Fx + D = Zx + P
    // x(F - Z) = C - D
    // x = (P - D)/(F - Z)
    if (isIntersect(line))
    {
        double Z = A/(-B);
        double F = line.A/(-1 * line.B);
        double P = C/(-B);
        double D = line.C/(-1 * line.B);
        double x = (P - D)/(F - Z) ;
        return getCoordinate(x);
    }
    return Point{__DBL_MAX__, __DBL_MAX__};
}

Point Line::getCoordinate(double x){
    // Ax + By + c = 0
    double y = (A*x + C) / (-1 * B);
    return Point{x,y};
}

Line::~Line()
{
}