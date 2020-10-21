#include <iostream>
#include <fstream>

template<typename T>
void workerWithStream(T &is){
    //do smth
}

int main(int argc, char ** argv){

    if (argc == 2)
    {
        std::ifstream ifs {argv[1]};
        workerWithStream(ifs);
    }
    else
        workerWithStream(std::cin);

    
    return EXIT_SUCCESS;
}