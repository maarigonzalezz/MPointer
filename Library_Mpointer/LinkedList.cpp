//
// Created by gonza on 30/08/2024.
//

#include "LinkedList.h"


void LinkedList::newMpointer(int id, void* adress){
    Node* newNode = new Node(id, adress, 1);
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

void LinkedList::addRef(int identifier){
    Node* current = head;
    while (current != nullptr) {
        if (current->id == identifier) {
            current->refCount ++;
            cout << "numero de ref: "<< current->refCount;
        }
        current = current->next;
    }
}

int LinkedList::deleteRef(int identifier){
    Node* current = head;
    while (current != nullptr) {
        if (current->id == identifier) {
            current->refCount -= 1;
            if (current->refCount == 0) {
               //llamar funcion
            }
            return current->refCount;
        }
        current = current->next;
    }
    return -1;
}

void LinkedList::deleteMpointer(int identifier){
    // Si la lista está vacía
    if (head == nullptr) {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }
    // Si el nodo a eliminar es el head
    if (head->id == identifier) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    // Buscar el nodo a eliminar
    Node* current = head;
    Node* previous = nullptr;
    while (current != nullptr && current->id != identifier) {
        previous = current;
        current = current->next;
    }
    // Si el nodo no fue encontrado
    if (current == nullptr) {
        std::cout << "Nodo con id " << identifier << " no encontrado." << std::endl;
        return;
    }
    // Desconectar el nodo de la lista
    previous->next = current->next;
    // Eliminar el nodo
    delete current;

}



