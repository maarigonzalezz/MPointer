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
        cout << ptr << endl;
    }
public:
    static Mpointer<T> New();
    T& operator*();
    T operator&();
};

template <typename T>
Mpointer<T> Mpointer<T>::New(){
    return Mpointer<T>();
}

template <typename T>
T& Mpointer<T>::operator*(){
    return *this->ptr;
}

template <typename T>
T Mpointer<T>::operator&(){
    return *ptr;
}





#endif //LIBRARY_MPOINTER_LIBRARY_H
