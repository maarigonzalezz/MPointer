//
// Created by gonza on 11/09/2024.
//

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include <library.h>

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
    ~DoubleLinkedList() = default;

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
