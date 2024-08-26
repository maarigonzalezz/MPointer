#include <iostream>
#include "library.h"

using namespace std;
int main() {
    Mpointer* ptr = new Mpointer();
    ptr->foo();
    cout << "hola";
    return 0;
}
