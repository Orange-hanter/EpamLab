#pragma once

struct Point
{
    double x;
    double y;
};

class Line
{
public:
    Line(Point p1, Point p2);
    Line(Point point);
    
    ~Line();

    bool isIntersect(Line line);
    static bool isIntersect(Line line1, Line line2);

    Point pointIntersection(Line line);
    static Point pointIntersection(Line line1, Line line2);

    Point getCoordinate(double x);

private:
    double A;
    double B;
    double C;
    
};

