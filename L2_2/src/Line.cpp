#include "Line.h"

Line::Line(Point p1, Point p2)
{
    A = p1.y - p2.y;
    B = p1.x - p2.x;
    C = (p1.x - p2.x) * p1.y + (p1.y - p2.y) * p1.x;
}

Line::Line(Point point)
{
    Point zero{0, 0};
    A = point.y - zero.y;
    B = point.x - zero.x;
    C = (point.x - zero.x) * point.y + (point.y - zero.y) * point.x;
}

bool Line::isIntersect(Line line)
{
    // y1 = Zx + C  - this Line
    // y2 = Fx + D  - line
    // Ax + C = Bx + D
    // the only wey when lines in intersect, it is the case F not equal Z
    double Z = A / (-B);
    double F = line.A / (-1 * line.B);

    if (Z == F)
        return false;
    else
        return true;
}

bool Line::isIntersect(Line line1, Line line2)
{
    // y1 = Zx + C  - this Line
    // y2 = Fx + D  - line
    // Ax + C = Bx + D
    // the only wey when lines in intersect, it is the case F not equal Z
    double Z = line1.A / (-1 * line1.B);
    double F = line2.A / (-1 * line2.B);

    if (Z == F)
        return false;
    else
        return true;
}

Point Line::pointIntersection(Line line)
{
    // y1 = Zx + P  - this Line
    // y2 = Fx + D  - line
    // Fx + D = Zx + P
    // x(F - Z) = C - D
    // x = (P - D)/(F - Z)
    if (isIntersect(line))
    {
        double Z = A / (-B);
        double F = line.A / (-1 * line.B);
        double P = C / (-B);
        double D = line.C / (-1 * line.B);
        double x = (P - D) / (F - Z);
        return getCoordinate(x);
    }
    return Point{1e20, 1e20};
}

Point Line::pointIntersection(Line line1, Line line2)
{
    // y1 = Zx + P  - this Line
    // y2 = Fx + D  - line
    // Fx + D = Zx + P
    // x(F - Z) = C - D
    // x = (P - D)/(F - Z)
    if (isIntersect(line1, line2))
    {
        double Z = line1.A / (-1 * line1.B);
        double F = line2.A / (-1 * line2.B);
        double P = line1.C / (-1 * line1.B);
        double D = line2.C / (-1 * line2.B);
        double x = (P - D) / (F - Z);
        return line1.getCoordinate(x);
    }
    return Point{1e20, 1e20};
}

Point Line::getCoordinate(double x)
{
    // Ax + By + c = 0
    double y = (A * x + C) / (-1 * B);
    return Point{x, y};
}

Line::~Line()
{
}