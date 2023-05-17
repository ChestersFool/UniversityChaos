#pragma once
#include <iostream>

using namespace std;

class Queue
{
private:
    int size, head, tail;
    int **arr;

public:
    Queue(int size);

    ~Queue();

    int Pop();

    void Push(int value, int from);

    void Output();

    int Size();

    int operator[](int index);

    int GetTail();

    int GetIndexFrom(int index);
};

Queue::Queue(int size)
{
    this->size = size;
    head = 0;
    tail = 0;
    arr = new int *[2];
    for (int i = 0; i < 2; i++)
        arr[i] = new int[size];
}

Queue::~Queue()
{
    for (int i = 0; i < 2; i++)
        delete[] arr[i];
    delete[] arr;
}

int Queue::Pop()
{
    if (Size() < 1)
        return 0;
    return arr[0][head++];
}

void Queue::Push(int value, int from)
{
    arr[0][tail] = value;
    arr[1][tail] = from;
    tail++;
}

void Queue::Output()
{
    int x;
    cout << "QUEUE: ";
    for (int i = 0; i < size; i++)
        cout << arr[0][i] << "(" << arr[1][i] << ") ";
}

int Queue::Size()
{
    return tail - head;
}

int Queue::operator[](int index)
{
    return arr[0][index];
}

int Queue::GetTail()
{
    return tail;
}

int Queue::GetIndexFrom(int index)
{
    for (int i = 0; i < size; i++)
        if (arr[0][i] == arr[1][index])
            return i;

    return 0;
}