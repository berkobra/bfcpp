#ifndef _CELLH_
#define _CELLH_

#include "config.hpp"

class cell{

    private:
        BF_INT val;
    public:
        cell(BF_INT val = 0);
        cell& operator++();
        cell& operator--();
        void setVal(BF_INT newVal);
        const BF_INT getVal();

};


#endif
