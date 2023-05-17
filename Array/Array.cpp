#pragma once
#include <iostream>
#include "Array.h"

using namespace std;

/// * CONSTRUCTORS

template <typename T>
Array<T>::Array()
{
    data = nullptr;
    size = 0;
}

template <typename T>
Array<T>::Array(uint16_t size)
{
    this->size = size;
    this->data = new T[this->size];
}

template <typename T>
Array<T>::Array(T *data, long size) : Array(size / sizeof(T))
{
    for (int i = 0; i < this->size; i++)
        this->data[i] = data[i];
}

template <typename T>
Array<T>::Array(const Array<T> &Outher) : Array(Outher.data, Outher.size * sizeof(T))
{
}

/// * DESTRUCTOR

template <typename T>
Array<T>::~Array()
{
    delete data;
}

/// * FUNCTIONS
template <typename T>
uint16_t Array<T>::GetSize()
{
    return this->size;
}

template <typename T>
T *Array<T>::GetData()
{
    T *new_data = new T[this->size];

    for (int i = 0; i < this->size; i++)
        new_data[i] = this->data[i];

    return new_data;
}

template <typename T>
void Array<T>::Output()
{
    cout << "size: " << this->size << endl;
    for (int i = 0; i < this->size; i++)
        cout << this->data[i] << " ";
    cout << endl;
}

template <typename T>
void Array<T>::Input()
{
    while (true)
    {
        try
        {
            cout << "enter size of array: ";
            cin >> this->size;
            break;
        }
        catch (const exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    cout << "size: " << this->size << endl;
    if (this->data != nullptr)
        delete this->data;

    for (int i = 0; i < this->size; i++)
        cin >> this->data[i];
}