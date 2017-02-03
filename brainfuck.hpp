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

void parse(const std::string& input, cellList& prog){
    int c = 0;
    char ins;
    cellList::node currentNode;
    while(true){
        try{
            ins = input.at(c);
        }
        catch (std::out_of_range const&){
            std::cout << "Index out of range, terminating..." << std::endl;
            break;
        }

        currentNode = *(prog.current);

        switch(ins){
            case '<':
                {
                //    --prog;
                    std::cout << "ins: <" << std::endl;
                    break;
                }
            case '>':
                {
                    //++prog;
                    std::cout << "ins: >" << std::endl;
                    break;
                }

            case '+':
                {
                    //*(prog.current)++;
                    //++(currentNode.valCell);
                    std::cout << "ins: +" << std::endl;
                    break;
                }

            case '-':
                {
                    //*(prog.current)--;
                    //--(currentNode.valCell);
                    std::cout << "ins: -" << std::endl;
                    break;
                }
            case '.':
                {
                    //std::cout << (char)currentNode.valCell.getVal();
                    std::cout << "ins: ." << std::endl;
                    break;
                }
            case ',':
                {
                    /* TODO:  checking of input size */
                    /*
                    int newVal;
                    std::cin >> newVal; 
                    currentNode.valCell.setVal(newVal);*/
                    std::cout << "ins: ," << std::endl;
                    break;
                }
            case '[':
                {
                    /*if (currentNode.valCell.getVal() == 0){
                        prog += nextParPos(c, input);
                    }*/
                    std::cout << "ins: [" << std::endl;
                    break;
                }
            case ']':
                {
                    /*if(currentNode.valCell.getVal()){
                        prog -= prevParPos(c, input);
                    }*/
                    std::cout << "ins: ]" << std::endl;
                    break;
                }
        }
    }
}
#endif
