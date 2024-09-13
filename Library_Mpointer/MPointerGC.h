//
// Created by gonza on 28/08/2024.
//
#include <iostream>
#include <mutex>
#include <thread>
#include <utility>
#ifndef MPOINTERGC_H
#define MPOINTERGC_H
#include "LinkedList.h"

using namespace std;


class MPointerGC {
    LinkedList list;
private:
    static MPointerGC *pinstance_;
    static std::mutex mutexx;
    int autoid = 0;

protected:
    MPointerGC() = default;
    ~MPointerGC() {
        // Ensure memory is freed before destruction
        Node* current = list.head;
        while (current != nullptr) {
            freeMpointer(current->adress);
            current = current->next;
        }
    }

public:
    MPointerGC(MPointerGC &other) = delete; // Prevent cloning
    void operator=(const MPointerGC &) = delete; // Prevent assignment

    static MPointerGC *GetInstance();
    int registerMemory(void* adress);
    void add_ref(int id);
    void delete_ref(int id);
    void freeMpointer(void* adress);
    void debug();
};

#endif //MPOINTERGC_H
