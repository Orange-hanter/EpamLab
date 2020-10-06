#include <stdio.h>
#include <stdlib.h>

#define ARG_COUNT 3

int main(const int argc, const char* argv[]){
    if (argc != ARG_COUNT)
    {
        fprintf(stderr, "ERROR!\n");
        return EXIT_FAILURE;
    }
    
    printf("%d - %d", atoi(argv[1]), atoi(argv[2]));
    return EXIT_SUCCESS;
}