#ifndef _BRAINFUCKH_
#define _BRAINFUCKH_

#include "cellList.hpp"
#include <iostream>
#include <string>

int nextParPos(int currentPos, const std::string& input){
    int c = 0;
    int newPos = 1;
    while(true){
        if(input.at(currentPos + newPos) == ']'){
            if(c){
                c--;
            }
            else{
                return newPos;
            }
        }
        else{
            if(input.at(currentPos + newPos) == '['){
                c++;
            }
        }
        newPos++;
    }
}

int prevParPos(int currentPos, const std::string& input){
    int c = 0;
    int newPos = 1;
    while(true){
        if(input.at(currentPos - newPos) == '['){
            if(c){
                c--;
            }
            else{
                return newPos;
            }
        }
        else{
            if(input.at(currentPos - newPos) == ']'){
                c++;
            }
        }
        newPos--;
    }
}

void parse(const std::string& input, cellList::cellList& prog){
    int c = 0;
    char ins;
    while(true){
        try{
            ins = input.at(c);
        }
        catch (std::out_of_range const&){
            std::cout << "Index out of range, terminating..." << std::endl;
            break;
        }
        
        switch(ins){
            case '<':
                {
                    prog--;
                    break;
                }
            case '>':
                {
                    prog++;
                    break;
                }

            case '+':
                {
                    *(prog.current)++;
                    break;
                }

            case '-':
                {
                    *(prog.current)--;
                    break;
                }
            case '.':
                {
                    std::cout << (char)(*(prog.current));
                    break;
                }
            case ',':
                {
                    /* TODO:  checking of input size */
                    int newVal;
                    std::cin >> newVal; 
                    *(prog.current).setVal(newVal);
                    break;
                }
            case '[':
                {
                    if (*(prog.current) == 0){
                        prog += nextParPos(c, input);
                    }
                    break;
                }
            case ']':
                {
                    if(*(prog.current)){
                        prog -= prevParPos(c, input);
                    }
                    break;
                }
        }
    }
}
#endif
