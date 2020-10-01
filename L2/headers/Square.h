#include "Figure.hpp"

namespace Figures{

    class Square: protected Figure{
    public:
        Square();
        Square(Square fig1, Square fig2);

        static bool isIntersect(Square fig1, Square fig2);
        static Square* IntersectArea(Square fig1, Square fig2);


        ~Square();

    private:
    
    };

}