#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

template <typename T>
struct arr_coff
{
    T *data;
    int n;

    void input_n();
    void data_get_mem();
    void random_data();
    void print_data();
};

template <typename T>
arr_coff<T> operator+(arr_coff<T> a, arr_coff<T> b);

template <typename T>
arr_coff<T> operator-(arr_coff<T> a, arr_coff<T> b);

template <typename T>
arr_coff<T> operator*(arr_coff<T> a, arr_coff<T> b);

int main()
{
    srand(time(NULL));

    arr_coff<int> a, b;
    a.input_n();
    a.data_get_mem();
    a.random_data();
    a.print_data();

    cout << endl;
    b.input_n();
    b.data_get_mem();
    b.random_data();
    b.print_data();

    arr_coff<int> c = a + b;
    cout << "\noperator+\t";
    c.print_data();
    c = a - b;
    cout << "\noperator-\t";
    c.print_data();
    c = a * b;
    cout << "\noperator*\t";
    c.print_data();
    return 0;
}

template <typename T>
void arr_coff<T>::input_n()
{
    do
    {
        cout << "Enter n: ";
        cin >> n;
    } while (n <= 0);
}

template <typename T>
void arr_coff<T>::data_get_mem()
{
    data = new T[n];
}

template <typename T>
void arr_coff<T>::random_data()
{
    int temp, x;
    for (int i = 0; i < n; i++)
    {
        temp = rand() % 10;
        x = rand() % 2;
        if (x)
            temp *= -1;
        data[i] = temp;
    }
}

template <typename T>
void arr_coff<T>::print_data()
{
    for (int i = 0; i < n; i++)
        cout << data[i] << "x**" << i << " ";
}

template <typename T>
arr_coff<T> operator+(arr_coff<T> a, arr_coff<T> b)
{
    arr_coff<int> temp;
    if (a.n >= b.n)
        temp.n = a.n;
    else
        temp.n = b.n;

    int x = abs(a.n - b.n);
    temp.data_get_mem();
    for (int i = 0; i < (temp.n - x); i++)
        temp.data[i] = a.data[i] + b.data[i];

    if (a.n > b.n)
        for (int i = (temp.n - x); i < temp.n; i++)
            temp.data[i] = a.data[i];
    else if (b.n > a.n)
        for (int i = (temp.n - x); i < temp.n; i++)
            temp.data[i] = b.data[i];

    return temp;
}

template <typename T>
arr_coff<T> operator-(const arr_coff<T> a, const arr_coff<T> b)
{
    arr_coff<T> temp;
    if (a.n >= b.n)
        temp.n = a.n;
    else
        temp.n = b.n;

    int x = abs(a.n - b.n);
    temp.data_get_mem();
    for (int i = 0; i < temp.n - x; i++)
        temp.data[i] = a.data[i] - b.data[i];

    if (a.n > b.n)
        for (int i = (temp.n - x); i < temp.n; i++)
            temp.data[i] = a.data[i];
    else if (b.n > a.n)
        for (int i = (temp.n - x); i < temp.n; i++)
            temp.data[i] = b.data[i];

    return temp;
}

template <typename T>
arr_coff<T> operator*(const arr_coff<T> a, const arr_coff<T> b)
{
    arr_coff<T> temp;
    temp.n = a.n + b.n - 1;
    temp.data_get_mem();
    for (int i = 0; i < temp.n; i++)
        temp.data[i] = 0;

    for (int i = 0; i < a.n; i++)
        for (int j = 0; j < b.n; j++)
            temp.data[i + j] += a.data[i] * b.data[j];

    return temp;
}