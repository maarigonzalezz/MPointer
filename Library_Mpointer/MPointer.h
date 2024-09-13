#ifndef LIBRARY_MPOINTER_LIBRARY_H
#define LIBRARY_MPOINTER_LIBRARY_H
#include <iostream>
#include <optional>
#include "MPointerGC.h"

using namespace std;
template <typename T>
class Mpointer {
    MPointerGC* garbagecollector = MPointerGC::GetInstance();
private:
    int assignedID{};
    T* ptr = nullptr;  // Atributo que es un puntero a un objeto de tipo T

    //Constructor
    Mpointer(){
        ptr = new T();
        if (ptr != nullptr) {
            assignedID = MPointerGC::GetInstance()->registerMemory(ptr);
        }
        cout << "MPointer::New" << endl;
    }
public:
    //Constructor copy 1
    Mpointer(const Mpointer & other){
        ptr = (other.ptr);
        assignedID = (other.assignedID); // Asignar el mismo ID para añadir una ref
        MPointerGC::GetInstance()->add_ref(assignedID);
        //cout << "MPointer::Constructor Copy" << endl;
    }

    Mpointer(const std::nullptr_t nullValue)
    {
        ptr = nullptr; // Set the internal pointer to nullptr
        assignedID = -1; // Use a special value (-1) to indicate no ID for nullptr
        //cout << "MPointer::Constructor Copy 2" << endl;
    }
    // Destructor
    ~Mpointer(){
        if (assignedID != -1) {
            MPointerGC::GetInstance()->delete_ref(assignedID);
        }
        cout << "MPointer::Destructor" << assignedID << endl;
    }

    // Genera un nuevo Mpointer sin llamar al constructor directamente
    static Mpointer<T> New()
    {
        return Mpointer<T>();
    }


    // Sobrecarga de *, accede a la memoria de *ptr para que se le asigne un valor
    T& operator*(){
        //cout << "MPointer::*" << endl;
        return *this->ptr;
    }

    // Sobrecarga de &, devuelve el valor de ptr
    T operator&(){
        //cout << "MPointer::&" << endl;
        return *ptr;
    }

    T* operator->() {
        //std::cout << "MPointer::->" << std::endl;
        return this->ptr;
    }

    // Operador de asignación para apuntar a null
    Mpointer<T>& operator=(std::nullptr_t)
    {
        ptr = nullptr;  // Assign internal pointer to nullptr
        if (assignedID != -1) {
            MPointerGC::GetInstance()->delete_ref(assignedID); // Reduce ref count for the current ID
        }
        assignedID = -1; // Mark the ID as -1 to indicate nullptr
        return *this;
    }

    // Operador de asignación para el mismo tipo T
    template <typename U> //usamos U para guardar un valor de cualquier tipo
    Mpointer<T>& operator=(const U& valor) {
        static_assert(std::is_same_v<T, U>, "Tipos incompatibles"); //se compara que el tipo de U sea el mismo de mpointer
        *ptr = valor; //hace el cambio
        //cout << "MPointer::=" << endl;
        return *this;
    }

    // Operador de asignación para otro Mpointer<T>
    Mpointer<T>& operator=(const Mpointer<T>& puntero) {
        if (this != &puntero) {
            ptr = (puntero.ptr); //hace un shallow copy para que tengan la misma dirr.
            MPointerGC::GetInstance()->add_ref(puntero.assignedID);
            MPointerGC::GetInstance()->delete_ref(assignedID);
            assignedID = puntero.assignedID;
            //cout << "MPointer::=" << endl;
        }
        return *this;
    }

    // Sobrecarga del operador de igualdad
    bool operator==(const Mpointer<T>& other) const {
        // Comparar si los dos punteros apuntan a la misma dirección de memoria
        cout << "COMPARACION" << endl;
        return this->ptr == other.ptr;
    }

};

#endif //LIBRARY_MPOINTER_LIBRARY_H
