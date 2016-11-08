//Brainfuck compiler

#include <iostream>
#include <fstream>
#include <string>

#define CELL_COUNT 30000

//TODO: doubly linked list

int main(int argc, char **argv){
    std::ifstream f;
    f.open(argv[1]);
    std::string line, complete;
    while(std::getline(f, line)){
        complete += line;
    }
    std::cout << complete << std::endl;
    return 0;
}
