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

int MPointerGC::registerMemory(void* adress){
   this->autoid ++;
    int iD = this->autoid;
    this->list.newMpointer(iD, adress);
    return iD;
}

void MPointerGC::add_ref(int id){
    list.addRef(id);
}

bool MPointerGC::delete_ref(int id) {
    int ref = list.deleteRef(id);
    if (ref == 0) {
        return true;
    }
    return false;
}

void MPointerGC::debug(){
    list.print();
}




/*void ThreadBar(){
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    MPointerGC* singleton = MPointerGC::GetInstance("BAR");
    std::cout << singleton->value() << "\n";
}*/
