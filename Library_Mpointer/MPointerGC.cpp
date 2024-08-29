//
// Created by gonza on 28/08/2024.
//

#include "MPointerGC.h"

#include <utility>
MPointerGC* MPointerGC::pinstance_{nullptr};
std::mutex MPointerGC::mutexx;

MPointerGC *MPointerGC::GetInstance()
{
    std::lock_guard<std::mutex> lock(mutexx);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new MPointerGC();
    }
    return pinstance_;
}

void MPointerGC::add(int value, string adr){
    Node* newNode = new Node(value, move(adr));
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->Next != nullptr) {
            temp = temp->Next;
        }
        temp->Next = newNode;
    }
}


/*void ThreadBar(){
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    MPointerGC* singleton = MPointerGC::GetInstance("BAR");
    std::cout << singleton->value() << "\n";
}*/
