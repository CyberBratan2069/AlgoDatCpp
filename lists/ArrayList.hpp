/***********************************************************************************************************************
 * @created Christian Reiswich
 * @date 03.02.2026
 **********************************************************************************************************************/


#pragma once
#include <cstddef>
#include <iostream>
#include <stdexcept>

template <typename E>
class ArrayList {
private:
    int sizeCount;
    int capacity;
    E* elementArray;

    void resize(const int newCapacity) {
        if (newCapacity < 4) newCapacity = 4;
        E* newElementArray = new E[newCapacity];
        for (int index=0; index< sizeCount; index++) {
            newElementArray[index] = elementArray[index];
        }
        delete[] elementArray;
        elementArray = newElementArray;
        capacity     = newCapacity;
    }

public:
    ArrayList() : sizeCount(0), capacity(4) {
        elementArray = new E[capacity];
    }

    ~ArrayList() {
        delete[] elementArray;
    }

    bool add(const E& element) {
        if (sizeCount == capacity) {
            resize(capacity * 2);
        }

        elementArray[sizeCount++] = element;
        return true;
    }

    bool addByIndex(const int index, const E& element) {
        if (index < 0 || index > sizeCount) {
            return false;
        }

        if (sizeCount == capacity) {
            resize(capacity * 2);
        }

        for (int currentIndex=sizeCount; currentIndex> index; currentIndex--) {
            elementArray[currentIndex] = elementArray[currentIndex - 1];
        }

        elementArray[index] = element;
        sizeCount++;
        return true;
    }

    bool setByIndex(const int index, const E& element) {
        if (index < 0 || index > sizeCount) {
            return false;
        }

        delete elementArray[index];
        elementArray[index] = element;
        return true;
    }

    E removeByIndex(int index) {
        if (index < 0 || index >= sizeCount) {
            throw std::out_of_range("Index out of Range!");
        }

        E elementToRemove = elementArray[index];

        for (int currentIndex=index; currentIndex< sizeCount-1; currentIndex++) {
            elementArray[currentIndex] = elementArray[currentIndex + 1];
        }

        sizeCount--;

        if (sizeCount > 0 && sizeCount <= capacity/4) {
            resize(capacity/2);
        }

        return elementToRemove;
    }

    bool removeByElement(E element) {
        const int index = indexOf(element);
        if (index == -1) return false;
        removeByIndex(index);
        return true;
    }

    void clear() {
        sizeCount = 0;
        resize(4);
    }

    E get(int index) {
        if (index < 0 || index >= sizeCount) {
            throw std::out_of_range("Index out of Range!");
        }
        return elementArray[index];
    }

    int indexOf(const E& element) {
        for (int currentIndex=0; currentIndex< sizeCount; currentIndex++) {
            if (elementArray[currentIndex] == element) {
                return currentIndex;
            }
        }
        return -1;
    }

    bool contains(const E& element) {
        for (int currentIndex=0; currentIndex< sizeCount; currentIndex++) {
            if (elementArray[currentIndex] == element) {
                return true;
            }
        }
        return false;
    }


    int size() const {
        return sizeCount;
    }

    bool isEmpty() const {
        return sizeCount == 0;
    }

    E* toArray() {
        E* newArray = new E[sizeCount];
        for (int index=0; index< sizeCount; index++) {
            newArray[index] = elementArray[index];
        }

        return newArray;
    }


    class Iterator {
    private:
        E* ptr;
        E* endPtr;

    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = E;
        using difference_type = std::ptrdiff_t;
        using pointer = E*;
        using reference = E&;


        Iterator(E* p, E* end) : ptr(p), endPtr(end) {}

        bool operator!=(const Iterator& other) const {
            return ptr != other.ptr;
        }

        Iterator& operator++() {
            if (ptr == endPtr) throw std::out_of_range("No such element");
            ptr++;
            return *this;
        }

        E& operator*() const {
            if (ptr == endPtr) throw std::out_of_range("No such element");
            return *ptr;
        }
    };

    Iterator begin() {
        return Iterator(&elementArray[0], &elementArray[sizeCount]);
    }

    Iterator end() {
        return Iterator(&elementArray[sizeCount], &elementArray[sizeCount]);
    }

};


