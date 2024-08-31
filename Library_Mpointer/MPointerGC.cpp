//
// Created by gonza on 28/08/2024.
//

#include "MPointerGC.h"

#include <utility>
MPointerGC* MPointerGC::pinstance_{nullptr};
std::mutex MPointerGC::mutexx;


// Controla el acceso a la instancia
MPointerGC *MPointerGC::GetInstance()
{
    std::lock_guard<std::mutex> lock(mutexx);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new MPointerGC();
    }
    return pinstance_;
}

// Genera un ID y ademas lo registra en la linked list con la direccion de memoria
int MPointerGC::registerMemory(void* adress){
   this->autoid ++;
    int iD = this->autoid;
    this->list.newMpointer(iD, adress);
    return iD;
}

// Llama el metodo de la linked list para que añada una referencia
void MPointerGC::add_ref(int id){
    list.addRef(id);
}

// Funcion booleana que verifica si ya no existen referencias
bool MPointerGC::delete_ref(int id) {
    int ref = list.deleteRef(id);
    if (ref == 0) {
        return true;
    }
    return false;
}

// Función debug, llama a linked list para que imprima los datos
void MPointerGC::debug(){
    list.print();
}
