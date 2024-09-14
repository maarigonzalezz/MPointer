//
// Created by gonza on 13/09/2024.
//
#include <gtest/gtest.h>
#include "MPointer.h"
#include "MPointerGC.h"

// Clase Pruebita para probar MPointer
struct  Pruebita {
    int value = 0;
};

// Pruebas para MPointer
TEST(MPointerTest, ConstructorAndAssignment) {
    Mpointer<int> p1 = Mpointer<int>::New();
    p1 = 10;
    ASSERT_EQ(&p1, 10);

    Mpointer<int> p2 = p1;
    ASSERT_EQ(&p2, 10);
    ASSERT_EQ(p1.get(), p2.get());

}

TEST(MPointerTest, NullptrAssignment) {
    Mpointer<Pruebita> p1 = Mpointer<Pruebita>::New();
    p1 = nullptr;
    ASSERT_EQ(p1.get(), nullptr);
}

TEST(MPointerTest, Destructor) {
    {
        Mpointer<Pruebita> p = Mpointer<Pruebita>::New();
        p->value = 30;
        ASSERT_EQ(p->value, 30);
    }
    // Verifica que el destructor libera la memoria.
    // Esto puede requerir funciones adicionales en MPointerGC para verificar la liberación.
}

TEST(MPointerTest, EqualityOperator) {
    Mpointer<int> p1 = Mpointer<int>::New();
    p1 = 40;
    Mpointer<int> p2 = Mpointer<int>::New();
    p2 = 40;
    ASSERT_FALSE(p1 == p2);

    p2 = p1;
    ASSERT_TRUE(p1 == p2);
}

// Pruebas para MPointerGC
TEST(MPointerGCTest, Singleton) {
    MPointerGC* gc1 = MPointerGC::GetInstance();
    MPointerGC* gc2 = MPointerGC::GetInstance();
    ASSERT_EQ(gc1, gc2);
}

TEST(MPointerGCTest, RegisterMemory) {
    MPointerGC* gc = MPointerGC::GetInstance();
    Pruebita* d = new Pruebita(50);
    int id = gc->registerMemory(d);
    ASSERT_NE(id, 0);
}

TEST(MPointerGCTest, AddAndDeleteRef) {
    MPointerGC* gc = MPointerGC::GetInstance();
    Pruebita* d = new Pruebita(60);
    int id = gc->registerMemory(d);
    gc->add_ref(id);
    gc->delete_ref(id);
    // Verifica que la memoria se libera correctamente.
}

TEST(MPointerGCTest, FreeMemory) {
    MPointerGC* gc = MPointerGC::GetInstance();
    Pruebita* d = new Pruebita(70);
    int id = gc->registerMemory(d);
    gc->delete_ref(id);
    // Verifica que la memoria se libera correctamente.
}

TEST(MPointerGCTest, DebugFunction) {
    MPointerGC* gc = MPointerGC::GetInstance();
    Pruebita* d = new Pruebita(80);
    gc->registerMemory(d);
    gc->debug();
    // Asegúrate de que la función debug() se ejecute sin errores.
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    std::cout<< "HOLAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << std::endl;
    return RUN_ALL_TESTS();
}