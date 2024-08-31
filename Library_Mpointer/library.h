#ifndef LIBRARY_MPOINTER_LIBRARY_H
#define LIBRARY_MPOINTER_LIBRARY_H
#include <iostream>

#include "MPointerGC.h"

using namespace std;
template <typename T>
class Mpointer {
    MPointerGC* garbagecollector = MPointerGC::GetInstance();
private:
    int assignedID;
    T* ptr = nullptr;  // Atributo que es un puntero a un objeto de tipo T

    //Constructor
    Mpointer(){
        ptr = new T();
        assignedID = MPointerGC::GetInstance()->registerMemory(ptr);
        //cout << assignedID;
    }
public:
    Mpointer(const Mpointer & other){
        ptr = (other.ptr);
        assignedID = (other.assignedID); //asignar el mismo ID para añadir una ref
        MPointerGC::GetInstance()->add_ref(assignedID);
    } //Es un constructor copy

    //Destructor
    ~Mpointer(){
        if (MPointerGC::GetInstance()->delete_ref(assignedID)) {
            ptr = nullptr;
            cout << "delete ptr destructor" << endl;
        }
    }

    //genera un nuevo Mpointer sin llamar al constructor directamente
    static Mpointer<T> New()
    {
        return Mpointer<T>();
    }


    //sobrecarga de *, accede a la memoria de *ptr para que se le asigne un valor
    T& operator*(){
        return *this->ptr;
    }

    //sobrecarga de &, devuelve el valor de ptr
    T operator&(){
        return *ptr;
    }


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
            MPointerGC::GetInstance()->add_ref(puntero.assignedID);
            bool dtonant = MPointerGC::GetInstance()->delete_ref(assignedID);
            delete_ptr(dtonant);
            assignedID = puntero.assignedID;
        }
        return *this;
    }

    void delete_ptr(bool dtonant) {
        if (dtonant == true) {
            delete ptr;
            ptr = nullptr;
            cout << "delete ptr" << endl;
        }
    }
};

#endif //LIBRARY_MPOINTER_LIBRARY_H
