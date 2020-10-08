#include <iostream>
#include "Square.h"

using namespace std;

int main()
{
    //TODO: remove this code to test file, after then like you understand CTest or BoostTest or Catch2
    Square *sq1 = new Square(Point{0, 10}, Point{10, 0});
    Square *sq2 = new Square(Point{0, 4}, Point{4, 0});
    Square *sq3 = new Square(Point{5, 15}, Point{15, 5});

    cout << Square::isIntersect(sq1, sq2) << endl
         << Square::isIntersect(sq1, sq3) << endl
         << Square::isIntersect(sq1, sq3) << endl
         << Square::isIntersect(sq2, sq3) << endl;
         
    Square *sq4 = Square::IntersectArea(sq1, sq3);
    return 0;
}