#ifndef _CELLH_
#define _CELLH_


class cell(int val){
    int val;
}

cell& cell::operator++();
cell& cell::operator--();
void cell::setVal(int newVal);
int cell::getVal();

#endif
