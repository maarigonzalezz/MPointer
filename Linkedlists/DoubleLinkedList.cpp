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
    ++length;
}

// Imprimir la lista hacia adelante
void DoubleLinkedList::printForward() const {
    Mpointer<Nod3> current = head;
    while (current != nullptr) {
        std::cout << "PRINT NODE FORWARD: " << current->value << endl;
        current = current->next;
    }
    std::cout << std::endl;
}

// Imprimir la lista hacia atrás
void DoubleLinkedList::printBackward() const {
    Mpointer<Nod3> current = tail;
    while (current != nullptr) {
        std::cout << "PRINT NODE BACKWARDS: " << current->value << endl;
        current = current->prev;
    }
    std::cout << std::endl;
}

int DoubleLinkedList::getLength() const {
    return length;
}

Mpointer<Nod3> DoubleLinkedList::getNodeAt(int index) const {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Index out of bounds");
    }
    Mpointer<Nod3> current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current;
}

int DoubleLinkedList::get(int index) const {
    return getNodeAt(index)->value;
}

void DoubleLinkedList::set(int index, int val) {
    Mpointer<Nod3> node = getNodeAt(index);
    node->value = val;
}

