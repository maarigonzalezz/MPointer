#ifndef LIBRARY_MPOINTER_LIBRARY_H
#define LIBRARY_MPOINTER_LIBRARY_H
#include <iostream>

using namespace std;
template <typename T>
class Mpointer {
private:
    T* ptr = nullptr;  // Atributo que es un puntero a un objeto de tipo T

    Mpointer()
    {
        cout << "se crea:";
        ptr = new T(); //Reserva memoria para el valor T
        cout << ptr;
    }
public:
    static Mpointer<T> New();
};

template <typename T>
Mpointer<T> Mpointer<T>::New(){
    return Mpointer<T>();
}

#endif //LIBRARY_MPOINTER_LIBRARY_H
