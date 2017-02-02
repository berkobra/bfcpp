//Brainfuck compiler

#include <iostream>
#include <fstream>
#include <string>
#include "brainfuck.hpp"

int main(int argc, char **argv){
    /* read the input file to a string */
    std::ifstream f;
    f.open(argv[1]);
    std::string line, complete;
    while(std::getline(f, line)){
        complete += line;
    }
    
    /* init the list */
    cellList prog = cellList();
    /* Do the thing */
    parse(complete, prog);
    return 0;
}
