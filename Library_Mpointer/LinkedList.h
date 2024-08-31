//
// Created by gonza on 30/08/2024.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

struct Node
{
    int id;
    void* adress = nullptr;
    int refCount = 0;
    Node* next = nullptr;
};

// Lista enlazada
class LinkedList {
private:
    Node* head;     // Puntero al primer nodo de la lista

public:
    // Constructor de la lista
    LinkedList() : head(nullptr) {}

    // Destructor de la lista
    ~LinkedList() = default;

    //añadir un nuevo pointer
    void newMpointer(int id, void* adress, int refcount);
    void addRefCount(int identifier);
    void deleteRef(int identifier);
};




#endif //LINKEDLIST_H
