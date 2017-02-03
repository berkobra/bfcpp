#include "cell.hpp"

cell::cell(BF_INT initVal){
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

void cell::setVal(BF_INT newVal){
    val = newVal;
}

const BF_INT cell::getVal(){
    return val;
}
