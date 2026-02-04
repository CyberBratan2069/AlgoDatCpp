/***********************************************************************************************************************
 * @created Christian Reiswich
 * @date 04.02.2026
 **********************************************************************************************************************/

#pragma once
#include <stdexcept>

template<typename E>
class LinkedStack {
private:
    struct Node {
        E element;
        Node* successor;

        explicit Node(E e) : element(e), successor(nullptr) {}
    };

    Node* topNode;

public:
    LinkedStack() : topNode(nullptr) {}

    ~LinkedStack() {
        while (!isEmpty()) pop();
    }

    bool isEmpty() const {
        return topNode == nullptr;
    }

    E peek() {
        if (isEmpty()) throw std::runtime_error("No Element founded!, Stack is empty!");
        return topNode->element;
    }

    E push(const E& element) {
        Node* addedNode = new Node(element);
        if (isEmpty()) {
            topNode = addedNode;
        } else {
            topNode->successor = addedNode;
            topNode = addedNode;
        }
        return addedNode->element;
    }

    E pop() {
        if (isEmpty()) throw std::runtime_error("No Element founded!, Stack is empty!");
        E elementToRemove = topNode->element;
        topNode = topNode->successor;
        delete topNode;
        return elementToRemove;
    }
};
