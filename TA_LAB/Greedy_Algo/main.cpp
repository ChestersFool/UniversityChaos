#include <iostream>
#include <algorithm>

using namespace std;

void foo(int **dots, int n);

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    int **dots = new int *[2];
    for (int i = 0; i < 2; i++)
        dots[i] = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter x0, x1 for dot " << i + 1 << ": ";
        cin >> dots[0][i] >> dots[1][i];
    }

    cout << '\n';
    for (int i = 0; i < n; i++)
        cout << "x0- " << dots[0][i] << " x1- " << dots[1][i] << "\t";

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (dots[1][j] > dots[1][j + 1])
            {
                swap(dots[1][j], dots[1][j + 1]);
                swap(dots[0][j], dots[0][j + 1]);
            }

    cout << '\n';
    for (int i = 0; i < n; i++)
        cout << "x0- " << dots[0][i] << " x1- " << dots[1][i] << "\t";
    // 6 7 3 5 1 3

    cout << "\nRESULT\n";
    int prev = 0, k = 0, counter = 0;
    while (k < n)
    {
        while (dots[0][k] <= prev)
            k++;
        if (dots[0][k] <= prev)
            break;
        cout << "x0- " << dots[0][k] << " x1- " << dots[1][k] << "\t";
        prev = dots[1][k];
        counter++;
        k++;
    }
    cout << "\nCounter - " << counter;
    return 0;
}
