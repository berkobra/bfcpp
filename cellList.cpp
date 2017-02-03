#include "cellList.hpp"

cellList::cellList(){
    cell* initCell = new cell();
    current = new node(nullptr, nullptr, *initCell);
}

//create next node if it does not exist
cellList& cellList::operator++(){
    if(current->next == nullptr){
        cell* newNext = new cell();
        current->next = new node(current, nullptr, *newNext);
    }
    current = current->next;
    return *this;
}

//create prev node if it does not exist
cellList& cellList::operator--(){
    if(current->prev == nullptr){
        cell* newPrev = new cell();
        current->prev = new node(nullptr, current, *newPrev);
    }
    current = current->prev;
    return *this;
}

cellList& cellList::operator+=(int c){
    for(int i = 0; i < c; i++){
        ++(*this);
    }
    return *this;
}

cellList& cellList::operator-=(int c){
    for(int i = 0; i < c; i++){
        --(*this);
    }
    return *this;
}
