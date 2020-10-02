#include <vector>

typedef struct Point
{
    double x;
    double y;
};


class Figure{
 public:
    Figure(double x = 0, double y = 0){ 
        points.push_back(Point{x,y});
    }

    Figure(Point point, ...){
        va_list valist; 
    }

    void changeCoordinate(double dX, double dY){
        for(auto point : points){
            point.x += dX;
            point.y += dY;
        }
    }
 
 protected:
    std::vector<Point> points;

};