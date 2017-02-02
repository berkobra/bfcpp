#ifndef _CELLH_
#define _CELLH_


class cell{
    int val;
};

cell::cell(int val = 0);
cell& cell::operator++();
cell& cell::operator--();
void cell::setVal(int newVal);
int cell::getVal();

#endif
