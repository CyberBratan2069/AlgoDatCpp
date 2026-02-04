/***********************************************************************************************************************
* @created Christian Reiswich
 * @date 03.02.2026
 **********************************************************************************************************************/


#pragma once
#include <exception>


template<typename E>
class LinkedQueue {
private:
    struct Node {
        E element;
        Node* successor;

        Node(E e) : element(e), successor(nullptr) {}
    };

    Node* firstNode;
    Node* lastNode;

public:
    LinkedQueue() {
        firstNode = new Node(E());
        lastNode = firstNode->successor;
    }

    // Check Queue
    bool empty() {
        if (firstNode == nullptr) return true;
        return false;
    }

    // Get first Element in Queue
    E first() {
        if (firstNode == nullptr) throw std::exception("No Element founded!");
        return firstNode->element;
    }

    // adding an element to the end of the queue
    E enqueue(E element) {
        Node addedNode = new Node(element);
        if (firstNode == nullptr) {
            firstNode = addedNode;
            lastNode  = addedNode;
        } else {
            lastNode->successor = addedNode;
            lastNode = addedNode;
        }
        return addedNode.element;
    }

    //removing an element from the front of the queue
    E dequeue() {
        if (firstNode == nullptr) throw std::exception("No Element founded!");
        E removedElement = firstNode->element;
        firstNode = firstNode->successor;
        if (firstNode == nullptr) lastNode = nullptr;
        return removedElement;
    }
};
