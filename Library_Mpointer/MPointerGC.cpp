//
// Created by gonza on 28/08/2024.
//

#include "MPointerGC.h"

#include <utility>
MPointerGC* MPointerGC::pinstance_{nullptr};
std::mutex MPointerGC::mutexx;


// Controla el acceso a la instancia
MPointerGC *MPointerGC::GetInstance() {
    std::lock_guard<std::mutex> lock(mutexx);
    if (pinstance_ == nullptr) {
        pinstance_ = new MPointerGC();
    }
    return pinstance_;
}

// Genera un ID y lo registra en la lista enlazada
int MPointerGC::registerMemory(void* adress) {
    std::lock_guard<std::mutex> lock(mutexx); // Thread safety
    this->autoid++;
    int iD = this->autoid;
    this->list.newMpointer(iD, adress);
    return iD;
}

// Añade una referencia
void MPointerGC::add_ref(int id) {
    std::lock_guard<std::mutex> lock(mutexx); // Thread safety
    list.addRef(id);
}

// Resta una referencia y libera si es necesario
void MPointerGC::delete_ref(int id) {
    std::lock_guard<std::mutex> lock(mutexx); // Thread safety
    int ref = list.deleteRef(id);
    if (ref == 0) {
        void* adr = list.getAdress(id);
        if (adr != nullptr) {
            cout << "Se va a liberar la memoria de ID: " << id << endl;
            this->freeMpointer(adr);
        } else {
            cout << "Error: Dirección no encontrada para ID: " << id << endl;
        }
    }
}

// Libera memoria correctamente
void MPointerGC::freeMpointer(void* adress) {
    if (adress != nullptr) {
        free(adress); // Use delete for memory allocated with 'new'
        cout << "MPointer Deleted" << endl;
    } else {
        cout << "Error: Dirección de memoria nula." << endl;
    }
}

// Función debug para imprimir la lista de referencias
void MPointerGC::debug() {
    std::lock_guard<std::mutex> lock(mutexx); // Thread safety
    list.print();
}