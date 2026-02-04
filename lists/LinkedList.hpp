/***********************************************************************************************************************
 * @created Christian Reiswich
 * @date 03.02.2026
 **********************************************************************************************************************/


#pragma once
#include <cstddef>
#include <ctype.h>
#include <iostream>
#include <stdexcept>

template <typename E>
class LinkedList {
private:
    struct Node {
        E element;
        Node* successor;

        explicit Node(E e) : element(e), successor(nullptr) {}
    };

    Node* firstNode;
    Node* lastNode;
    int numberOfElements;
    int successorAccessCounter;

public:
    LinkedList() : numberOfElements(0), successorAccessCounter(0) {
        firstNode = new Node(E());
        lastNode  = firstNode;
    };

    ~LinkedList() {
        Node* currentNode = firstNode;
        while (currentNode != nullptr) {
            Node* nextNode = currentNode->successor;
            delete currentNode;
            currentNode = nextNode;
        }
    };

    bool add(E element) {
        Node* addedNode = new Node(element);
        lastNode->successor = addedNode;
        lastNode = addedNode;
        numberOfElements++;
        return true;
    }

    E get(const int index) {
        if (index < 0 || index >= numberOfElements) {
            throw std::out_of_range("Out of Bounds!");
        }

        Node* nodeAtCurrentIndex = firstNode->successor;
        for (int currentIndex=0; currentIndex< index; currentIndex++) {
            nodeAtCurrentIndex = nodeAtCurrentIndex->successor;
            successorAccessCounter++;
        }

        return nodeAtCurrentIndex->element;
    }

    E removeByIndex(const int index) {
        if (index < 0 || index >= numberOfElements) {
            throw std::out_of_range("Out of Bounds!");
        }

        Node* previousNode = firstNode; // null
        Node* nodeToRemove = firstNode->successor; // A
        for (int currentIndex=0; currentIndex< index; currentIndex++) {
            previousNode = nodeToRemove; // null -> A
            nodeToRemove = nodeToRemove->successor; // A -> B
            successorAccessCounter++;
        }
        // A -> B -> C
        previousNode->successor = nodeToRemove->successor;
        // A    ->   C
        if (nodeToRemove == lastNode) {
            lastNode = previousNode;
        }

        delete nodeToRemove;
        numberOfElements--;
        return  nodeToRemove->element;
    }

    bool removeByElement(E element) {
        Node* previousNode = firstNode;
        Node* nodeToRemove = firstNode->successor;

        while (nodeToRemove != nullptr) {
            if (nodeToRemove->element == element) {
                previousNode->successor = nodeToRemove->successor;
                if (nodeToRemove == lastNode) {
                    lastNode = previousNode;
                }
                delete nodeToRemove;
                numberOfElements--;
                return true;
            }
            previousNode = nodeToRemove;
            nodeToRemove = nodeToRemove->successor;
            successorAccessCounter++;
        }
        return false;
    }

    int indexOf(E element) {
        Node* nodeToRemove = firstNode->successor;
        int index = 0;

        while (nodeToRemove != nullptr) {
            if (nodeToRemove->element == element) {
                return index;
            }
            nodeToRemove = nodeToRemove->successor;
            index++;
            successorAccessCounter++;
        }
        return -1;
    }

    int size() const {
        return numberOfElements;
    }

    int getSuccessorAccessCounter() const {
        return successorAccessCounter;
    }

    void resetSuccessorAccessCounter() {
        successorAccessCounter = 0;
    }

    class Iterator {
    private:
        Node* currentNode;
        int& counterRef;

    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type        = E;
        using difference_type   = std::ptrdiff_t;
        using pointer           = E*;
        using reference         = E&;


        Iterator(Node* starNode, int& counter) : currentNode(starNode), counterRef(counter) {}

        bool operator!=(const Iterator& other) const {
            return currentNode != other.currentNode;
        }

        Iterator& operator++() {
            if (currentNode != nullptr) {
                currentNode = currentNode->successor;
                counterRef++;
            }
            return *this;
        }

        E& operator*() {
            return currentNode->element;
        }
    };

    Iterator begin() {
        return Iterator(firstNode->successor, successorAccessCounter);
    }

    Iterator end() {
        return Iterator(nullptr, successorAccessCounter);
    }

};
