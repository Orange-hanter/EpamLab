#include "Square.h"

using namespace Figures;

Square::Square(){}

Square::Square(Point point_a, Point point_b):Figure(point_a, point_b){}

bool Square::isIntersect(Square figure_1, Square figure_2){
    
    for(auto point: figure_1.points){
        Point highPointFig2 = figure_2.points[0];
        Point lowPointFig2 = figure_2.points[1];
        if (point.x )
        {
            /* code */
        }
        
    }

    return false;
}

Square::~Square(){
    
}