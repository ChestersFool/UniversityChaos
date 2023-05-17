#pragma once
#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
class TreeData
{
private:
    template <typename t = T>
    class _NodeData
    {
    public:
        int count;
        t data;
        _NodeData *pLeft, *pRight;

        _NodeData(t data)
        {
            this->data = data;
            this->count = 1;
            this->pLeft = nullptr;
            this->pRight = nullptr;
        }

        _NodeData()
        {
            this->data = NULL;
            this->count = 0;
            this->pLeft = nullptr;
            this->pRight = nullptr;
        }
    };

    _NodeData<T> *head;

public:
    TreeData();

    _NodeData<T> *GetHead();

    void AddNodeData(T data);

    void Output(_NodeData<T> *pNode, int tab);

    int Search(T data);

    friend void inputFileTree(FILE *fTree, TreeData<char *> &divNameTree, TreeData<char *> &NameTree, TreeData<int> &allExpTree, TreeData<int> &expTree);
};

class TreeChar
{
private:
    class _NodeChar
    {
    public:
        int count;
        char data[100];
        _NodeChar *pLeft, *pRight;

        _NodeChar(char *data)
        {
            strcpy(this->data, data);
            this->count = 1;
            this->pLeft = nullptr;
            this->pRight = nullptr;
        }

        _NodeChar()
        {
            this->data[0] = '\0';
            this->count = 0;
            this->pLeft = nullptr;
            this->pRight = nullptr;
        }
    };

    _NodeChar *head;

public:
    TreeChar();

    _NodeChar *GetHead();

    void AddNodeData(char *data);

    void Output(_NodeChar *pNode, int tab);

    int Search(char *data);

    friend void inputFileTree(FILE *fTree, TreeChar &divNameTree, TreeChar &NameTree, TreeData<int> &allExpTree, TreeData<int> &expTree);
};

TreeChar::TreeChar()
{
    head = nullptr;
}

TreeChar::_NodeChar *TreeChar::GetHead()
{
    return head;
}

void TreeChar::AddNodeData(char *data)
{
    if (head == nullptr)
    {
        head = new _NodeChar(data);
        return;
    }

    _NodeChar *current;
    current = head;

    while (current->data[0] != '\0')
    {
        if (strcmp(current->data, data) == 1)
        {
            if (current->pRight == nullptr)
            {
                current->pRight = new _NodeChar(data);
                return;
            }
            current = current->pRight;
            continue;
        }
        else if (strcmp(current->data, data) == -1)
        {
            if (current->pLeft == nullptr)
            {
                current->pLeft = new _NodeChar(data);
                return;
            }
            current = current->pLeft;
            continue;
        }
        else
        {
            current->count++;
            return;
        }
    }
}

void TreeChar::Output(_NodeChar *pNode, int tab)
{
    if (pNode != nullptr)
    {
        Output(pNode->pRight, tab + 1);
        cout << endl;
        for (int i = 0; i < tab; i++)
            cout << "\t\t";

        cout << pNode->data << "(" << pNode->count << ")";
        Output(pNode->pLeft, tab + 1);
    }
}

int TreeChar::Search(char *data)
{
    _NodeChar *current;
    current = head;

    while ((strcmp(current->data, data) != 0))
    {
        if (strcmp(current->data, data) == 1)
        {
            current = current->pRight;
            continue;
        }
        else if (strcmp(current->data, data) == -1)
        {
            current = current->pLeft;
            continue;
        }
    }

    return current->count;
}

template <typename T>
TreeData<T>::TreeData()
{
    head = nullptr;
}

template <typename T>
TreeData<T>::_NodeData<T> *TreeData<T>::GetHead()
{
    return head;
}

template <typename T>
void TreeData<T>::AddNodeData(T data)
{
    if (head == nullptr)
    {
        head = new _NodeData<T>(data);
        return;
    }

    _NodeData<T> *current;
    current = head;

    while (current->data != NULL)
    {
        if (data > current->data)
        {
            if (current->pRight == nullptr)
            {
                current->pRight = new _NodeData<T>(data);
                return;
            }
            current = current->pRight;
            continue;
        }
        else if (data < current->data)
        {
            if (current->pLeft == nullptr)
            {
                current->pLeft = new _NodeData<T>(data);
                return;
            }
            current = current->pLeft;
            continue;
        }
        else
        {
            current->count++;
            return;
        }
    }
}

template <typename T>
void TreeData<T>::Output(_NodeData<T> *pNode, int tab)
{
    if (pNode != nullptr)
    {
        Output(pNode->pRight, tab + 1);
        cout << endl;
        for (int i = 0; i < tab; i++)
            cout << "\t\t";

        cout << pNode->data << "(" << pNode->count << ")";
        Output(pNode->pLeft, tab + 1);
    }
}

template <typename T>
int TreeData<T>::Search(T data)
{
    _NodeData<T> *current;
    current = head;

    while (current->data != data)
    {
        if (data > current->data)
        {
            current = current->pRight;
            continue;
        }
        else if (data < current->data)
        {
            current = current->pLeft;
            continue;
        }
    }

    return current->count;
}