#ifndef _CELLLISTH_
#define _CELLLISTH_

#include "cell.h"

class cellList(){
    struct node{
        node* prev;
        node* next;
        cell valCell;
    }

    node* current;
}

cellList::cellList();
cellList& cellList::operator++();
cellList& cellList::operator--();
cellList& cellList::operator+=(int c);
cellList& cellList::operator-=(int c);

#endif
