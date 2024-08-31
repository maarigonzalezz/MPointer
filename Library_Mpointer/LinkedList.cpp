//
// Created by gonza on 30/08/2024.
//

#include "LinkedList.h"
#include "MPointerGC.h"

void LinkedList::newMpointer(int id, void* adress, int refcount){
    Node* newNode = new Node(id, adress, refcount);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void LinkedList::addRefCount(int identifier){
    Node* current = head;
    while (current != nullptr) {
        if (current->id == identifier) {
            current->refCount ++;
        }
        current = current->next;
    }
}

void LinkedList::deleteRef(int identifier){
    Node* current = head;
    while (current != nullptr) {
        if (current->id == identifier) {
            current->refCount -= 1;
            if (current->refCount == 0) {
               //llamar funcion
            }
        }
        current = current->next;
    }
}




