// IntArray.hpp
#ifndef INTARRAY_HPP
#define INTARRAY_HPP

#include <iostream>
#include <cstddef> 
#include <stdexcept>

class IntArray {
private:
    unsigned long long* array;
    size_t capacity;
    size_t length;

public:
    IntArray();
    ~IntArray();
    IntArray(const IntArray& other);
    unsigned long long operator[](size_t index) const;   
    void push_back(unsigned long long element);
    unsigned long long& operator[](size_t index);
    size_t size() const;
    void clear();
    void print() const;
    IntArray& operator=(const IntArray& other);
};

#endif // INTARRAY_HPP
