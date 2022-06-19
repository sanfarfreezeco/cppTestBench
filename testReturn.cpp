#include <iostream>

int ii = 0;
int xx = 5;
int yy = 8;
int zz;

void test() {
    zz = xx + yy;
    if(ii == 0) {
        if(zz == 0) {
            zz = 1;
        } else {
            return;
        }
    } else {
        std::cout << zz;
    }
}