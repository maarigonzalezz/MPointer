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
        while (current != nullptr) {

            Mpointer<Nod3> next = current->next;
            current->prev = nullptr;
            current->next = nullptr;
            current = nullptr;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    void add(int value);
    void printForward() const;
    void printBackward() const;
    int getLength() const;
    int get(int index) const;
    void set(int index, int value);
private:
    Mpointer<Nod3> head = nullptr;
    Mpointer<Nod3> tail = nullptr;
    int length = 0;
    Mpointer<Nod3> getNodeAt(int index) const;

};



#endif //DOUBLELINKEDLIST_H
