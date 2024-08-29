#include <iostream>
#include "library.h"

using namespace std;
int main() {
    int valor;
    int valor2;
    Mpointer<int> Myptr = Mpointer<int>::New();
    Mpointer<string> Myptr2 = Mpointer<string>::New();
    Mpointer<int> Myptr3 = Mpointer<int>::New();
    *Myptr = 5;
    *Myptr3 = 10;
    //Myptr = "alo"; se cae
    Myptr3 = Myptr;
    //Myptr = 9;
    valor2 = &Myptr3;
    valor = &Myptr;
    cout << valor << endl << valor2;


    cout << "            hola";
    return 0;
}
