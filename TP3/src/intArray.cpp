// IntArray.cpp
#include "../include/intArray.hpp"

IntArray::IntArray() : array(nullptr), capacity(0), length(0) {}

IntArray::~IntArray() {
    delete[] array;
}

IntArray::IntArray(const IntArray& other) : array(nullptr), capacity(other.capacity), length(other.length) {
    array = new unsigned long long[capacity];
    for (size_t i = 0; i < length; i++) {
        array[i] = other.array[i];
    }
}

unsigned long long IntArray::operator[](size_t index) const {
    if (index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return array[index];
}

void IntArray::push_back(unsigned long long element) {
    if (length >= capacity) {
        size_t newCapacity = capacity == 0 ? 1 : capacity * 2;
        unsigned long long* newArray = new unsigned long long[newCapacity];
        for (size_t i = 0; i < length; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }
    array[length++] = element;
}


unsigned long long& IntArray::operator[](size_t index) {
    if (index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return array[index];
}

size_t IntArray::size() const {
    return length;
}

void IntArray::clear() {
    delete[] array;
    array = nullptr;
    capacity = 0;
    length = 0;
}

void IntArray::print() const {
    for (size_t i = 0; i < length; ++i) {
        std::cout << array[i] << (i < length - 1 ? " " : "\n");
    }
}