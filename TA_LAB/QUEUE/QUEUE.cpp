#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

template <typename T>
class Queue
{
private:
    int size, head, tail, hdp, tlp; // headplus, tailpuls
    T *arr;

    void resize_copy()
    {
        T *temparr = new T[size];
        tail = tlp % (size / 2);
        int x = hdp, i;
        for (i = 0; i < tlp - x; i++)
        {
            head = (hdp + i) % (size / 2);
            temparr[i] = arr[head];
        }
        hdp = 0;
        tlp = i;
        delete[] arr;
        arr = temparr;
    }

public:
    Queue()
    {
        size = 5;
        head = 0;
        tail = 0;
        hdp = 0;
        tlp = 0;
        arr = new T[size];
    }
    ~Queue()
    {
        delete[] arr;
    }

    void write_to_queue(T value)
    {
        if (tlp >= size)
        {
            size *= 2;
            resize_copy();
        }
        tail = tlp % size;
        arr[tail] = value;
        tlp++;
    }

    T read_from_queue()
    {
        T result;
        if (!(hdp >= tlp + 1))
        {
            head = hdp % size;
            result = arr[head];
            hdp++;
            if (tlp - hdp < size / 3)
            {
                size *= (float(2) / 3);
            }
        }
        return result;
    }

    void print_queue()
    {
        int x;
        cout << "QUEUE: ";
        for (int i = 0; i < tlp - hdp; i++)
        {
            x = (hdp + i) % size;
            cout << arr[x] << " ";
        }
    }

    void print_size()
    {
        cout << endl
             << "SIZE - " << size;
    }
};

int main()
{
    srand(time(NULL));

    Queue<int> a, b;
    int n;
    cout << "Enter n: ";
    cin >> n;
    int temp, x;

    for (int i = 0; i < n; i++)
    {
        temp = rand() % 100 + 1;
        x = rand() % 2;
        if (x)
            temp *= -1;
        a.write_to_queue(temp);
    }
    a.print_queue();

    int s = 0;
    for (int i = 0; i < n; i++)
    {
        x = a.read_from_queue();
        b.write_to_queue(x);
        s += abs(x);
    }

    for (int i = 0; i < n; i++)
    {
        x = b.read_from_queue();
        a.write_to_queue(x);
    }
    a.write_to_queue(s);

    cout << endl;
    a.print_queue();

    return 0;
}
