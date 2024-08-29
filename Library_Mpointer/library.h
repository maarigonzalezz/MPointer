#ifndef LIBRARY_MPOINTER_LIBRARY_H
#define LIBRARY_MPOINTER_LIBRARY_H
#include <iostream>

#include "MPointerGC.h"

using namespace std;
template <typename T>
class Mpointer {
    MPointerGC* garbagecollector = MPointerGC::GetInstance();
private:
    T* ptr = nullptr;  // Atributo que es un puntero a un objeto de tipo T

    //Constructor
    Mpointer(){
        ptr = new T();
        cout << T() << endl;
        //garbagecollector->add(T());
    }
public:
    Mpointer(const Mpointer & other){ptr = (other.ptr);} //Es un constructor copy

    //Destructor
    ~Mpointer(){
        delete ptr;
    }

    static Mpointer<T> New(); //metodo new
    T& operator*(); //sobrecarga de *
    T operator&(); //sobrecarga de &

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

//desarrollo

//Nos ayuda a generar un nuevo Mpointer sin llamar al constructor directamente
template <typename T>
Mpointer<T> Mpointer<T>::New(){
    return Mpointer<T>();
}

//Lo que hace es que accede a la memoria de *ptr para que se le asigne un valor
template <typename T>
T& Mpointer<T>::operator*(){
    return *this->ptr;
}

//Devuelve el valor de ptr
template <typename T>
T Mpointer<T>::operator&(){
    return *ptr;
}

#endif //LIBRARY_MPOINTER_LIBRARY_H
