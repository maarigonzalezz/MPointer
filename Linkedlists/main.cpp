#include <iostream>
#include "MPointer.h"
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


struct Example{
    int a = 0;
    int l = 0;
    int o = 0;
};

int main() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Mpointer<int> mp1 = Mpointer<int>::New();
    Mpointer<int> mp2 = Mpointer<int>::New();
    Mpointer<double> doub = Mpointer<double>::New();
    Mpointer<double> doub2 = Mpointer<double>::New();
    Mpointer<char> chari = Mpointer<char>::New();
    Mpointer<Example> example = Mpointer<Example>::New();
    example->a = 5;
    cout << "Mpointer usando structs: "<< example->a <<  endl;

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
    Sorters sorter;
    testlist.add(110);
    testlist.add(2);
    testlist.add(31);
    testlist.add(19);
    testlist.add(79);
    testlist.add(5);
    testlist.add(22);
    testlist.add(535);
    testlist.add(90);
    testlist.add(1);

    testlist.printForward();
    //testlist.printBackward();
    //sorter.bubbleSort(testlist);
    //sorter.insertionSort(testlist);
    int hi = testlist.getLength();
    sorter.quickSort(testlist, 0, hi - 1);
    testlist.printForward();


    MPointerGC::GetInstance()->debug();

    return 0;
}
