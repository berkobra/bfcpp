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

const int cell::getVal(){
    return val;
}
