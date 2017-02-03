/* cellList class test */

#include <iostream>
#include <sstream>
#include <string>
#include "cellList.hpp"

void listPrint(const cellList& ls){

    cellList::node* p = ls.current->prev;
    cellList::node* n = ls.current->next;
    cell currCell = ls.current->valCell;
    
    std::ostringstream buf;
    buf << "<--( ";
    if(p){
        buf << p->valCell.getVal();
    }
    else{
        buf << "NULL";
    }
    
    buf << " ) -- ( " << currCell.getVal() << " ) -- ( ";

    if(n){
        buf <<  n->valCell.getVal();
    }
    else{
        buf << "NULL";
    } 
    
    buf << " )-->";

    std::cout << buf.str() << std::endl;

}

/* TESTS BEGIN HERE */
int main(){

    /* INITIALIZATION TESTS */

    cellList l1; /* only default init is available */
    listPrint(l1);
    
    /* INCREMENT & DECREMENT TESTS */

    ++l1;
    listPrint(l1);

    --l1;
    listPrint(l1);

    --l1;
    listPrint(l1);

    ++l1;
    listPrint(l1);

    l1.current->valCell.setVal(5);
    listPrint(l1);
    ++l1;
    l1.current->valCell.setVal(8);
    listPrint(l1);
    ++l1;
    l1.current->valCell.setVal(-3);
    listPrint(l1);
    --l1;
    --l1;
    --l1;
    l1.current->valCell.setVal(-9);
    listPrint(l1);
    --l1;
    l1.current->valCell.setVal(-2);
    listPrint(l1);
    --l1;
    l1.current->valCell.setVal(14);
    listPrint(l1);
    ++l1;
    ++l1;
    listPrint(l1);

    /* MULTI INCR & DECR TESTS */

    l1 += 2;
    listPrint(l1);

    l1 -= 4;
    listPrint(l1);
}


