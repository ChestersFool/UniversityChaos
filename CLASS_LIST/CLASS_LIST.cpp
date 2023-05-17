#include <iostream>

using namespace std;

template <typename T>
class list
{
public:
    list();
    ~list();

    void push_back(T value);                          // ++
    void push_after(T value = T(), int index = NULL); // ++
    void pop_front();
    void move_next_read();    // ++
    T read_data();            // ++
    void clear();             // ++
    T &operator[](int index); // ++
    int get_size();           // ++

private:
    template <typename t>
    class node
    {
    public:
        t data;
        node *pnext;

        node(t data = t(), node *pnext = nullptr)
        {
            this->data = data;
            this->pnext = pnext;
        }
    };

    int size;
    node<T> *head;
    node<T> *after;
    node<T> *read;
};

template <typename T>
list<T>::list()
{
    size = 0;
    head = nullptr;
    after = nullptr;
    read = nullptr;
}

template <typename T>
list<T>::~list()
{
    clear();
}

template <typename T>
void list<T>::push_back(T value)
{
    if (head == nullptr)
        head = new node<T>(value);
    else
    {
        node<T> *current = this->head;
        while (current->pnext != nullptr)
            current = current->pnext;
        current->pnext = new node<T>(value);
    }
    this->size++;
}

template <typename T>
void list<T>::push_after(T value, int index)
{
    node<T> *current;
    if (index != NULL)
    {
        int counter = 0;
        current = this->head;
        while (current != nullptr)
        {
            if (counter == index)
            {
                after = current;
                break;
            }
            current = current->pnext;
            counter++;
        }
    }
    current = after;
    if (current->pnext == nullptr)
    {
        current->pnext = new node<T>;
        current = current->pnext;
        current->data = value;
        current->pnext = nullptr;
        size++;
    }
    else
    {
        node<T> *temp;
        temp = new node<T>;
        temp->data = value;
        temp->pnext = current->pnext;
        current->pnext = temp;
        size++;
    }
}

template <typename T>
void list<T>::pop_front()
{
    node<T> *temp = head;
    head = head->pnext;
    delete temp;
    size--;
}

template <typename T>
void list<T>::move_next_read()
{
    if (read == nullptr)
    {
        read = head;
        return;
    }
    read = read->pnext;
}

template <typename T>
T list<T>::read_data()
{
    return read->data;
}

template <typename T>
void list<T>::clear()
{
    while (size)
        pop_front();
}

template <typename T>
T &list<T>::operator[](int index)
{
    node<T> *current = this->head;
    int count = 0;
    while (current != nullptr)
    {
        if (count == index)
            return current->data;
        current = current->pnext;
        count++;
    }
}

template <typename T>
int list<T>::get_size()
{
    return this->size;
}

int main()
{
    srand(time(NULL));
    list<int> a;

    int n = 4, temp;
    // cout << "ENTER N: ";
    // cin >> n;

    for (int i = 0; i < n; i++)
        a.push_back(temp = rand() % 10 + 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    a.push_after(a[0], n - 1);
    a.move_next_read();
    for (int i = 1; i < n; i++)
    {
        a.move_next_read();
        a.push_after(a.read_data());
    }

    n = a.get_size();
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}