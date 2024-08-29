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
    ~Mpointer(){
        delete ptr;
    }
    static Mpointer<T> New();
    T& operator*();
    T operator&();
    // Operador de asignación para el mismo tipo T
    template <typename U> //usamos U para guardar un valor de cualquier tipo
    Mpointer<T>& operator=(const U& valor) {
        static_assert(std::is_same_v<T, U>, "Tipos incompatibles"); //se compara que el tipo de U sea el mismo de mpointer
        *ptr = valor; //hace el cambio
        return *this;
    }

    // Operador de asignación para otro Mpointer<T>
    Mpointer<T>& operator=(const Mpointer<T>& puntero) {
        if (this != &puntero) {
            ptr = (puntero.ptr); //hace un shallow copy para que tengan la misma dirr.
        }
        return *this;
    }
};

//aaaaaaaaaaaaaaaaaaaaaaaaaaaa

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
