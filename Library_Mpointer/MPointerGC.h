//
// Created by gonza on 28/08/2024.
//
#include <iostream>
#include <mutex>
#include <thread>
#include <utility>
#ifndef MPOINTERGC_H
#define MPOINTERGC_H

using namespace std;


class MPointerGC {
private:
    static MPointerGC * pinstance_;
    static std::mutex mutexx;

protected:
    MPointerGC()= default;
    ~MPointerGC() = default;


public:

    MPointerGC(MPointerGC &other) = delete; //Evitar que se clone
    void operator=(const MPointerGC &) = delete;//Evitar que se copie
    static MPointerGC *GetInstance();
};

#endif //MPOINTERGC_H
