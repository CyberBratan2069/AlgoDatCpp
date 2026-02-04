/***********************************************************************************************************************
* @created Christian Reiswich
 * @date 04.02.2026
 **********************************************************************************************************************/


#pragma once
#include <stdexcept>


template<typename E>
class LinkedQueue {
private:
    struct Node {
        E element;
        Node* successor;

        explicit Node(const E& e) : element(e), successor(nullptr) {}
    };

    Node* firstNode;
    Node* lastNode;

public:
    LinkedQueue() : firstNode(nullptr), lastNode(nullptr) {}

    ~LinkedQueue() {
        while (!isEmpty()) dequeue();
    }

    // Check Queue
    bool isEmpty() const {
        if (firstNode == nullptr) return true;
        return false;
    }

    // Get first Element in Queue
    E first() {
        if (isEmpty()) throw std::runtime_error("No Element founded!");
        return firstNode->element;
    }

    // adding an element to the end of the queue
    E enqueue(E element) {
        Node* addedNode = new Node(element);
        if (isEmpty()) {
            firstNode = addedNode;
            lastNode  = addedNode;
        } else {
            lastNode->successor = addedNode;
            lastNode = addedNode;
        }
        return addedNode->element;
    }

    //removing an element from the front of the queue
    E dequeue() {
        if (isEmpty()) throw std::runtime_error("No Element founded!");
        E elementToRemove  = firstNode->element;
        firstNode = firstNode->successor;
        if (firstNode == nullptr) lastNode = nullptr;
        delete firstNode;
        return elementToRemove;
    }
};
