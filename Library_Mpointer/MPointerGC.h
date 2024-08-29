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
class Node {
public:
    int id;
    int value;
    int refcount;
    string Adress;
    Node* Next;

    Node(int val, string  adr) : value(val), refcount(0), Adress(move(adr)), Next(nullptr) {}
};


class MPointerGC {
private:
    static MPointerGC * pinstance_;
    static std::mutex mutexx;
    Node* head;

protected:
    MPointerGC() : head(nullptr){}
    ~MPointerGC() = default;


public:

    MPointerGC(MPointerGC &other) = delete; //Evitar que se clone
    void operator=(const MPointerGC &) = delete;//Evitar que se copie
    static MPointerGC *GetInstance();
    void add(int value, string adr);
};

#endif //MPOINTERGC_H
