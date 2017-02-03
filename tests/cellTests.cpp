/* Cell class test */

#include <iostream>
#include "cell.hpp"

int main(){

/* INITIALIZATION TESTS */

cell c1 = 5; /* initialize with parameter */
cell c2 = cell(); /* default initialization */
cell c3; /* test if this is same with c2 */

/* GETVAL TESTS */

int v1, v2, v3;
v1 = c1.getVal();
v2 = c2.getVal();
v3 = c3.getVal();

std::cout << "Value of Cell #1 is: " << v1 << std::endl;
std::cout << "Value of Cell #2 is: " << v2 << std::endl;
std::cout << "Value of Cell #3 is: " << v3 << std::endl;

/* SETVAL TESTS */

c3.setVal(6);
c2.setVal(-4);
v2 = c2.getVal();
v3 = c3.getVal();

std::cout << "Value of Cell #1 is: " << v1 << std::endl;
std::cout << "Value of Cell #2 is: " << v2 << std::endl;
std::cout << "Value of Cell #3 is: " << v3 << std::endl;

/* INCREMENT & DECREMENT TESTS */

--c1;
++c2;

v1 = c1.getVal();
v2 = c2.getVal();
v3 = c3.getVal();

std::cout << "Value of Cell #1 is: " << v1 << std::endl;
std::cout << "Value of Cell #2 is: " << v2 << std::endl;
std::cout << "Value of Cell #3 is: " << v3 << std::endl;
}
