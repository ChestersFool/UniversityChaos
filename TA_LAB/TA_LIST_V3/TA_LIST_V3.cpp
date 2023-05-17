#include <iostream>
#include <ctime>

using namespace std;

template <typename T>
struct list
{
    T data;
    list *next;
};

template <typename T>
void gen_list(list<T> *first, int n);

template <typename T>
void print_list(list<T> *first);

// template <typename T>
// void write_list_last(list<T> *first, T value);

template <typename T>
void write_list_after(list<T> *after, T value);

template <typename T>
T get_data_list(list<T> &x);

int main()
{
    srand(time(NULL));
    list<int> first;
    list<int> *x, *last;

    int n, temp;
    cout << "ENTER N: ";
    cin >> n;

    gen_list(&first, n);
    print_list(&first);
    x = &first;

    while (x->next != NULL)
    {
        x = x->next;
    }
    last = x;
    x = &first;

    for (int i = 0; i < n; i++)
    {
        temp = get_data_list(*x);
        write_list_after(last, temp);
        x = x->next;
    }

    cout << endl;
    print_list(&first);

    return 0;
}

template <typename T>
void gen_list(list<T> *first, int n)
{
    first->data = rand() % 10;
    for (int i = 0; i < n - 1; i++)
    {
        first->next = new list<T>;
        first = first->next;
        first->data = rand() % 10;
    }
    first->next = NULL;
}

template <typename T>
void print_list(list<T> *first)
{
    while (first != NULL)
    {
        cout << first->data << " ";
        first = first->next;
    }
}

// template <typename T>
// void write_list_last(list<T> *first, T value)
// {
//     while (first->next != NULL)
//     {
//         first = first->next;
//     }
//     first->next = new list<T>;
//     first = first->next;
//     first->data = value;
//     first->next = NULL;
// }

template <typename T>
void write_list_after(list<T> *after, T value)
{
    if (after->next == NULL)
    {
        after->next = new list<T>;
        after = after->next;
        after->data = value;
        after->next = NULL;
    }
    else
    {
        list<T> *temp;
        temp = new list<T>;
        temp->data = value;
        temp->next = after->next;
        after->next = temp;
    }
}

template <typename T>
T get_data_list(list<T> &x)
{
    return x.data;
}
