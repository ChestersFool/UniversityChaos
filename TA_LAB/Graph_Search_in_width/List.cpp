#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class List
{
public:
    List();
    ~List();

    void PushBack(int data);

    int PopFront();
    void Pop(int data);
    void Clear();

    void Output();

    int GetSize();

private:
    class node
    {
    public:
        int data;
        node *pnext;

        node(int data = 0, node *pnext = nullptr)
        {
            this->data = data;
            this->pnext = pnext;
        }
    };

    int size;
    node *head;
};

List::List()
{
    size = 0;
    head = nullptr;
}

List::~List()
{
    Clear();
}

void List::PushBack(int data)
{
    if (this->head == nullptr)
    {
        this->head = new node(data);
        this->size++;
        return;
    }

    node *current = this->head;
    while (current->pnext != nullptr)
        current = current->pnext;
    current->pnext = new node(data);

    this->size++;
}

int List::PopFront()
{
    int returnData = this->head->data;
    node *temp = this->head;

    this->head = head->pnext;
    delete temp;
    this->size--;

    return returnData;
}

void List::Pop(int data)
{
    if (this->head == nullptr)
        return;

    node *current = this->head;

    while (current->pnext != nullptr)
    {
        if (current->data == data)
        {
            node *temp = current->pnext;
            current->pnext = current->pnext->pnext;
            delete temp;
            this->size--;
            break;
        }
        current = current->pnext;
    }
}

void List::Clear()
{
    while (this->size)
        PopFront();
}

void List::Output()
{
    node *current = this->head;
    for (int j = 0; j < this->size; j++)
    {
        cout << current->data << "   ";
        current = current->pnext;
    }
}

int List::GetSize()
{
    return this->size;
}