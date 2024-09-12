#include <iostream>
#include "library.h"
#include "DoubleLinkedList.h"
#include "Sorters.h"
using namespace std;

Mpointer<int> foo(){
    Mpointer<int> temp2 = Mpointer<int>::New();
    Mpointer<int> temp = Mpointer<int>::New();
    temp = 666;

    MPointerGC::GetInstance()->debug();

    return temp;
}


struct Alo
{
    int a = 0;
    int l = 0;
    int o = 0;
};

int main() {
    Mpointer<int> mp1 = Mpointer<int>::New();
    Mpointer<int> mp2 = Mpointer<int>::New();
    Mpointer<double> doub = Mpointer<double>::New();
    Mpointer<double> doub2 = Mpointer<double>::New();
    Mpointer<char> chari = Mpointer<char>::New();
    Mpointer<Alo> ola = Mpointer<Alo>::New();
    ola->a = 5;
    cout << ola->a << "yayayayayayay" << endl;


    foo();

    MPointerGC::GetInstance()->debug();

    *mp1 = 100;
    mp2 = 55;
    chari = 'a';
    char a;

    Mpointer<int> mp3 = mp2;
    MPointerGC::GetInstance()->debug();

    mp3 = mp1;
    doub2 = doub;
    Mpointer<double> doub3 = Mpointer<double>::New();
    MPointerGC::GetInstance()->debug();

    DoubleLinkedList testlist;
    testlist.add(1);
    testlist.add(2);
    testlist.add(31);
    testlist.add(19);
    testlist.add(110);
    testlist.add(79);

    testlist.printForward();

    MPointerGC::GetInstance()->debug();

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));


    return 0;
}
