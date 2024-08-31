//
// Created by gonza on 30/08/2024.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

struct Node
{
    int id;
    void* adress = nullptr;
    int refCount = 0;
    Node* next = nullptr;
};

// Lista enlazada
class LinkedList {
   // MPointerGC* garbagecollector1 = MPointerGC::GetInstance();
private:
    Node* head;     // Puntero al primer nodo de la lista

public:
    // Constructor de la lista
    LinkedList() : head(nullptr) {}

    // Destructor de la lista
    ~LinkedList() = default;

    //añadir un nuevo pointer
    void newMpointer(int id, void* adress);
    void addRef(int identifier);
    int deleteRef(int identifier);
    void deleteMpointer(int identifier);
    Node* getInstance(int identifier);
};




#endif //LINKEDLIST_H
