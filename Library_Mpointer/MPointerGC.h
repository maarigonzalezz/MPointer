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
    static MPointerGC * pinstance_;
    static std::mutex mutexx;
    int autoid = 0;

protected:
    MPointerGC()= default;
    ~MPointerGC() = default;


public:

    MPointerGC(MPointerGC &other) = delete; //Evitar que se clone
    void operator=(const MPointerGC &) = delete;//Evitar que se copie
    static MPointerGC *GetInstance();
    int registerMemory(void* adress);
    void add_ref(int id);
    bool delete_ref(int id);

    //void freeMpointer()
};

#endif //MPOINTERGC_H
