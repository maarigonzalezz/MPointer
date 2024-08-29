#include <iostream>
#include "library.h"

using namespace std;
int main() {
    int valor;
    int valor2;
    int valor3;
    double valor4;
    Mpointer<int> Myptr = Mpointer<int>::New();
    Mpointer<double> Myptr2 = Mpointer<double>::New();
    Mpointer<int> Myptr3 = Mpointer<int>::New();
    //Overload *
    *Myptr = 5;
    *Myptr3 = 10;

    //overload =
    Myptr3 = Myptr;
    Mpointer<int> Myptr4 = Myptr;
    Myptr2 = 5.5;

    //Overload &
    valor2 = &Myptr3;
    valor = &Myptr;
    valor3 = &Myptr4;
    valor4 = &Myptr2;
    cout << valor << endl << valor2 << endl << valor3 << endl << valor4;


    cout << "            hola";
    return 0;
}
