#include <iostream>
#include <ctime>

using namespace std;

template <typename T>
class stack_on_array
{
private:
    int size, top;
    T *arr;

    void resize_copy()
    {
        T *temparr = new T[size];
        for (int i = 0; i < top; i++)
            temparr[i] = arr[i];
        delete[] arr;
        arr = temparr;
    }

public:
    stack_on_array()
    {
        top = 0;
        size = 10;
        arr = new T[size];
    }

    ~stack_on_array()
    {
        delete[] arr;
    }

    void write_to_stack(T value)
    {
        if (top >= size)
        {
            size *= 2;
            resize_copy();
        }
        arr[top++] = value;
    }

    T read_from_stack()
    {
        T result;
        if (!(top == 0))
        {
            result = arr[--top];
            if (top < size / 3)
            {
                size *= (float(2) / 3);
                resize_copy();
            }
        }
        return result;
    }

    void print_stack()
    {
        cout << "STACK: ";
        for (int i = 0; i < top; i++)
            cout << arr[i] << " ";
    }
};

int main()
{
    srand(time(NULL));

    stack_on_array<int> a, b;

    int n;
    float temp;
    cout << "Enter n: ";
    cin >> n;

    for (int i = 0; i < n; i++)
        a.write_to_stack(temp = (rand() % 100 + 1));

    a.print_stack();

    int s = 0, x;
    for (int i = 0; i < n; i++)
    {
        x = a.read_from_stack();
        s += x;
        b.write_to_stack(x);
    }

    a.write_to_stack(s);
    for (int i = 0; i < n; i++)
    {
        x = b.read_from_stack();
        a.write_to_stack(x);
    }

    cout << endl;
    a.print_stack();
}
