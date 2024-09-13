//
// Created by gonza on 30/08/2024.
//

#include "LinkedList.h"

// Agrega una nueva instancia a la clase
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

// Añade 1 al conteo de referencias
void LinkedList::addRef(int identifier){
    Node* current = head;
    while (current != nullptr) {
        if (current->id == identifier) {
            current->refCount ++;
            //cout << "numero de ref: "<< current->refCount << endl;
        }
        current = current->next;
    }
}

// Resta 1 al conteo de referencias
int LinkedList::deleteRef(int identifier){
    Node* current = head;
    while (current != nullptr) {
        if (current->id == identifier) {
            current->refCount -= 1;
            return current->refCount;
        }
        current = current->next;
    }
    return -1;
}

// Print los datos de cada nodo
void LinkedList::print(){
    Node* current = head;
    cout << "DEBUGGER" << endl;
    while (current != nullptr){
       cout << "ID: " << current->id << " RefCount: " << current->refCount  << " Adress: " << current->adress << endl;
        current = current->next;
    }
}

void* LinkedList::getAdress(int identifier){
    Node* current = head;
    while (current != nullptr) {
        if (current->id == identifier) {
            return current->adress;
        }
        current = current->next;
    }
    return nullptr;
}


// Cuando el conteo de referencias llega a 0 se elimina el nodo de la lista
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



