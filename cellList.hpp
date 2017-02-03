#ifndef _CELLLISTH_
#define _CELLLISTH_

#include "cell.hpp"

class cellList{
    public:
        struct node{
            node* prev;
            node* next;
            cell valCell;
            node(node* p = nullptr,
                 node* n = nullptr,
                 cell  c = cell())
                {
                    prev = p;
                    next = n;
                    valCell = c;
                }

        };

        node* current;
        cellList();
        cellList& operator++();
        cellList& operator--();
        cellList& operator+=(int c);
        cellList& operator-=(int c);
};


#endif
