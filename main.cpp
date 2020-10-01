#include <iostream>


class Test{
    public:
    Test(){ std::cout << "RUN CONSTRUCTOR";}
};

int main(int, char**) {
    Test test;
    std::cout << "Hello, world!\n";
}
