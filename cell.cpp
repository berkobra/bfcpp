#include "cell.hpp"

cell::cell(int initVal){
    val = initVal;
}

cell& cell::operator++(){
    val++;
    return *this;
}

cell& cell::operator--(){
    val--;
    return *this;
}

void cell::setVal(int newVal){
    val = newVal;
}

void cell::getVal(){
    return val;
}
