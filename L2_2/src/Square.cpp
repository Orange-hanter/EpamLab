#include "Square.h"

Square::Square() {}

Square::Square(Point point_a, Point point_b) : Figure(point_a, point_b) {}

bool Square::isIntersect(Square *figure_1, Square *figure_2)
{
    Point HighLeft{figure_1->points[0]},
        LowRight{figure_1->points[2]},
        HighRight{HighLeft.y, LowRight.x},
        LowLeft{HighLeft.x, LowRight.y};
    
    /*
   for (auto point : figure_1.points)
    {
        Point highPointFig2 = figure_2.points[0];
        Point lowPointFig2 = figure_2.points[1];
        if (point.x)
        {
            // code 
        }
    }
    */
    return false;
}

Square *Square::IntersectArea(Square *fig1, Square *fig2)
{
    //TODO: implement function
    return new Square(Point{0, 10}, Point{10, 0});
}

Square::~Square()
{
}