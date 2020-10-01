class Figure{
 public:
    Figure(double X = 0, double Y = 0):x{X},y{Y}{ /*TUTURUUUU!*/ }

    void changeCoordinate(double dX, double dY){
        x += dX;
        y += dY;
    }
 
 protected:
    double x;
    double y;

};