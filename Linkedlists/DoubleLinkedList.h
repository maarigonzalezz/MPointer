//
// Created by gonza on 11/09/2024.
//

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include <MPointer.h>

struct Nod3{
public:
    int value = 0;
    Mpointer<Nod3> next = nullptr;
    Mpointer<Nod3> prev = nullptr;

    Nod3() = default;
};


class DoubleLinkedList {
public:
    // Constructor de la lista
    DoubleLinkedList() = default;

    // Destructor de la lista
    ~DoubleLinkedList() {
        Mpointer<Nod3> current = head;
        cout << "id 0?" << endl;
        while (current != nullptr) {

            Mpointer<Nod3> next = current->next;  // Guardar el siguiente nodo
            cout << "aqi" << endl;
            current->prev = nullptr;  // Eliminar la referencia al nodo anterior
            cout << "aqui 2" << endl;
            current->next = nullptr;  // Eliminar la referencia al nodo siguiente
            cout << "aqui 3" << endl;
            current = nullptr;  // Eliminar el nodo actual (esto llamará al destructor de Mpointer)
            current = next;  // Avanzar al siguiente nodo
        }
        head = nullptr;
        tail = nullptr;
        length = 0;
        std::cout << "DESTRUCTOR DLL - Todos los nodos eliminados" << std::endl;
    }

    void add(int value);
    void printForward() const;  // Imprimir la lista hacia adelante
    void printBackward() const; // Imprimir la lista hacia atrás
    int getLength() const; // Conseguir el largo de la lista
    int get(int index) const;
    void set(int index, int value);
private:
    Mpointer<Nod3> head = nullptr;
    Mpointer<Nod3> tail = nullptr;
    int length = 0;
    Mpointer<Nod3> getNodeAt(int index) const; // Metodo para conseguir el indice

};



#endif //DOUBLELINKEDLIST_H
