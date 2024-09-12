//
// Created by gonza on 11/09/2024.
//

#include "DoubleLinkedList.h"

void DoubleLinkedList::add(int val) {
    Mpointer<Nod3> newNode = Mpointer<Nod3>::New();
    newNode->value = val;

    MPointerGC::GetInstance()->debug(); // Solo si necesitas debuggear

    // Comparar si `tail` es igual a `nullptr`
    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Imprimir la lista hacia adelante
void DoubleLinkedList::printForward() const {
    Mpointer<Nod3> current = head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Imprimir la lista hacia atrás
void DoubleLinkedList::printBackward() const {
    Mpointer<Nod3> current = tail;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

