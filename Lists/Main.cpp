/***********************************************************************************************************************
* @created Christian Reiswich
 * @date 03.02.2026
 **********************************************************************************************************************/

#pragma once
#include <iostream>
#include <string>
#include "ArrayList.hpp"
#include "LinkedList.hpp"

static int arrayListAccessCount = 0;

void resetArrayListAccessCount() {
    arrayListAccessCount = 0;
}

int getArrayListAccessCount() {
    return arrayListAccessCount;
}


/// HELPERS FOR LINKEDLIST
// List with values {1, 4, 9, 16 ... 100}
void fillLinkedList(LinkedList<int>& list, const int numberOfElements) {
    for (int i=0; i<= numberOfElements; i++) {
        list.add(i * i);
    }
}

void printLinkedListInForLoop(LinkedList<int>& list) {
    for (int i=0; i< list.size(); i++) {
        std::cout << list.get(i) << " ";
    }
    std::cout << std::endl;
}

void printLinkedListInForeachLoop(LinkedList<int>& list) {
    for (int element : list) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void printLinkedListInForLoopWithIterator(LinkedList<int>& list) {
    for (LinkedList<int>::Iterator it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


/// HELPERS FOR LINKEDLIST
// List with values {1, 4, 9, 16 ... 100}
void fillArrayList(ArrayList<int>& list, const int numberOfElements) {
    for (int i=0; i<= numberOfElements; i++) {
        list.add(i * i);
    }
}

void printArrayListInForLoop(ArrayList<int>& list) {
    for (int i=0; i< list.size(); i++) {
        std::cout << list.get(i) << " ";
    }
    std::cout << std::endl;
}

void printArrayListInForeachLoop(ArrayList<int>& list) {
    for (int element : list) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void printArrayListInForLoopWithIterator(ArrayList<int>& list) {
    for (ArrayList<int>::Iterator it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}



int main(int argc, char* argv[]) {
    int numberOfElements = 10;
    if (argc > 1) {
        numberOfElements = std::stoi(argv[1]);
    }

    std::cout << "--- LinkedList ----------------------\n";
    LinkedList<int> linkedList;
    fillLinkedList(linkedList, numberOfElements);

    std::cout << "--- LinkedList printed in for loop ---\n";
    linkedList.resetSuccessorAccessCounter();
    printLinkedListInForLoop(linkedList);
    std::cout << "Number of accesses to the successor: " << linkedList.getSuccessorAccessCounter() << "\n\n";

    std::cout << "--- LinkedList printed in foreach loop ---\n";
    linkedList.resetSuccessorAccessCounter();
    printLinkedListInForeachLoop(linkedList);
    std::cout << "Number of accesses to the successor: " << linkedList.getSuccessorAccessCounter() << "\n\n";

    std::cout << "--- LinkedList printed in for with iterator ---\n";
    linkedList.resetSuccessorAccessCounter();
    printLinkedListInForLoopWithIterator(linkedList);
    std::cout << "Number of accesses to the successor: " << linkedList.getSuccessorAccessCounter() << "\n\n";


    std::cout << "--- ArrayList -----------------------\n";
    ArrayList<int> arrayList;
    fillArrayList(arrayList, numberOfElements);

    std::cout << "--- ArrayList printed in for loop ---\n";
    resetArrayListAccessCount();
    printArrayListInForLoop(arrayList);
    std::cout << "Number of accesses to the elements: " << getArrayListAccessCount() << "\n\n";

    std::cout << "--- ArrayList printed in foreach loop ---\n";
    resetArrayListAccessCount();
    printArrayListInForLoop(arrayList);
    std::cout << "Number of accesses to the elements: " << getArrayListAccessCount() << "\n\n";

    std::cout << "--- ArrayList printed in for with iterator ---\n";
    resetArrayListAccessCount();
    printArrayListInForLoopWithIterator(arrayList);
    std::cout << "Number of accesses to the successor: " << getArrayListAccessCount() << "\n\n";


    return 0;
}