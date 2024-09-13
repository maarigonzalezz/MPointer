//
// Created by gonza on 30/08/2024.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

// Node, tiene todos los datos que necesita
struct Node
{
    int id = 0;
    void* adress = nullptr;
    int refCount = 0;
    Node* next = nullptr;
};

// Lista enlazada
class LinkedList {
public:
    Node* head;     // Puntero al primer nodo de la lista
    // Constructor de la lista
    LinkedList() : head(nullptr) {}

    // Destructor de la lista
    ~LinkedList() = default;

    void newMpointer(int id, void* adress);
    void addRef(int identifier);
    int deleteRef(int identifier);
    void deleteMpointer(int identifier);
    void print();
    void* getAdress(int identifier);
};




#endif //LINKEDLIST_H
