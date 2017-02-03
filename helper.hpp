#ifndef _HELPERH_
#define _HELPERH_

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
 #endif
