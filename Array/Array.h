#pragma once
#include <stdint.h>

template <typename T>
class Array
{
private:
    T *data;
    uint16_t size;

public:
    /// * CONSTRUCTORS
    Array();
    Array(uint16_t size);
    Array(T *data, long size);
    Array(const Array<T> &Outher);
    /// * DESTRUCTOR
    ~Array();
    /// * FUNCTIONS
    uint16_t GetSize();
    T *GetData();
    void Output();
    void Input();
};
