#include <iostream>
#include "library.h"

using namespace std;
int main() {
    Mpointer<int> Myptr = Mpointer<int>::New();
    Mpointer<string> Myptr2 = Mpointer<string>::New();
    *Myptr = 5;
    int valor = &Myptr;
    cout << valor;

    cout << "            hola";
    return 0;
}
