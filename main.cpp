#include <iostream>
void foo( int a){
    std::cout << a + 1;
}

class Test{
    public:
    Test(){ std::cout << "RUN CONSTRUCTOR";}
};

int main(int, char**) {
   // Test test;
    int gg = 0;
    int& pGG = gg; 
    foo(pGG);
    //std::cout << "Hello, world!\n";
    std::cout << gg;
}
