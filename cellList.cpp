#include "cellList.h"

cellList::cellList(){
    cell* initCell = new cell();
    current = new node(NULL, NULL, *initCell);
}

//create next node if it does not exist
cellList& cellList::operator++(){
    if(current->next == NULL){
        cell* newNext = new cell();
        current->next = new node(current, NULL, *newNext);
    }
    current = current->next;
    return *this;
}

//create prev node if it does not exist
cellList& cellList::operator--(){
    if(current->prev == NULL){
        cell* newPrev = new cell();
        current->prev = new node(NULL, current, *newPrev);
    }
    current = current->prev;
    return *this;
}

cellList& cellList::operator+=(int c){
    for(int i = 0; i < c; i++){
        (*this)++;
    }
    return *this;
}

cellList& cellList::operator-=(int c){
    for(int i = 0; i < c; i++){
        (*this)--;
    }
    return *this;
}
