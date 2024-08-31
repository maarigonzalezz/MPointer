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



/*void ThreadBar(){
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    MPointerGC* singleton = MPointerGC::GetInstance("BAR");
    std::cout << singleton->value() << "\n";
}*/
