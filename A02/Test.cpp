#include <iostream> //std::cout, std::cin, etc.
#include <cstdlib> //C++ version of stdlib.h
#include <cstring> //C++ version of string.h
#include <string>

int main(int argc, char *argv[])
{
    int x;
    printf("%d\n",argc);
    for (x=0; x<argc; x++)
        printf("%s\n",argv[x]);
    return 0;
}