#pragma once
#include <iostream>

using namespace std;

class Queue
{
private:
    int size, head, tail;
    int *arr;

public:
    Queue(int size);

    ~Queue();

    int Pop();

    void Push(int value);

    void Output();

    int Size();

    int operator[](int index);

    int GetTail();
};

Queue::Queue(int size)
{
    this->size = size;
    head = 0;
    tail = 0;
    arr = new int[size];
}

Queue::~Queue()
{
    delete[] arr;
}

int Queue::Pop()
{
    if (Size() < 1)
        return 0;
    return arr[head++];
}

void Queue::Push(int value)
{
    arr[tail] = value;
    tail++;
}

void Queue::Output()
{
    int x;
    cout << "QUEUE: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int Queue::Size()
{
    return tail - head;
}

int Queue::operator[](int index)
{
    return arr[index];
}

int Queue::GetTail()
{
    return tail;
}
