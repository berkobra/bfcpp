#ifndef _BRAINFUCKH_
#define _BRAINFUCKH_

#ifdef _DEBUG_
#undef _DEBUG_
#endif 

#include "cellList.hpp"
#include <iostream>
#include <string>

/* need only at debug mode */
#ifdef _DEBUG_
#include "helper.hpp"
#endif

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
        newPos++;
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
            //std::cout << "Index out of range, terminating..." << std::endl;
            break;
        }

        currentNode = *(prog.current);

        switch(ins){
            case '<':
                {
                    --prog;
#ifdef _DEBUG_
                    std::cout << "char: " << c
                    << " ins: <" << std::endl;
#endif
                    break;
                }
            case '>':
                {
                    ++prog;
#ifdef _DEBUG_
                    std::cout << "char: " << c
                    << " ins: >" << std::endl;
#endif
                    break;
                }

            case '+':
                {
                    //*(prog.current)++;
                    //++(currentNode.valCell);
                    ++prog.current->valCell;
#ifdef _DEBUG_
                    std::cout << "char: " << c
                    << " ins: +" << std::endl;
#endif
                    break;
                }

            case '-':
                {
                    //*(prog.current)--;
                    //--(currentNode.valCell);
                    --prog.current->valCell;
#ifdef _DEBUG_
                    std::cout << "char: " << c
                    << " ins: -" << std::endl;
#endif
                    break;
                }
            case '.':
                {
                    std::cout << (char) currentNode.valCell.getVal();
#ifdef _DEBUG_
                    std::cout << "char: " << c
                    << " ins: ." << std::endl;
#endif
                    break;
                }
            case ',':
                {
                    /* TODO:  checking of input size */
                    
                    int newVal;
                    std::cin >> newVal; 
                    currentNode.valCell.setVal(newVal);
#ifdef _DEBUG_
                    std::cout << "char: " << c
                    << " ins: ," << std::endl;
#endif
                    break;
                }
            case '[':
                {
                    if (currentNode.valCell.getVal() == 0){
                        //prog += nextParPos(c, input);
                        c += nextParPos(c, input);
                    }
#ifdef _DEBUG_
                    std::cout << "char: " << c
                    << " ins: [" << std::endl;
#endif
                    break;
                }
            case ']':
                {
                    if(currentNode.valCell.getVal()){
                        //prog -= prevParPos(c, input);
                        c -= prevParPos(c, input);
                    }
#ifdef _DEBUG_
                    std::cout << "char: " << c
                    << " ins: ]" << std::endl;
#endif
                    break;
                }
        }
#ifdef _DEBUG_
        listPrint(prog);
#endif
        c++;
    }
}
#endif
