#include <iostream>

using namespace std;

int main()
{
    int i, j;
    // * 1
    int n = 4, m = 1;
    int cars[4][4] = {
        {4, 3, 1, 1},
        {3, 1, 1, 1},
        {1, 1, 4, 1},
        {1, 1, 1, 2}};
    // * 2
    // int n = 5, m = 2;
    // int cars[5][5] = {
    //     {4, 2, 3, 1, 1},
    //     {3, 3, 1, 1, 1},
    //     {1, 2, 1, 4, 3},
    //     {1, 3, 1, 2, 3},
    //     {2, 4, 5, 4, 3}};
    // * 3
    // int n, m;
    // cout << "Enter n, m: ";
    // cin >> n >> m;
    // int **cars = new int *[n];
    // for (i = 0; i < n; i++)
    //     cars[i] = new int[m];
    // for (i = 0; i < n; i++)
    // {
    //     for (j = 0; j < n; j++)
    //     {
    //         cout << "[" << i << "][" << j << "]:";
    //         cin >> cars[i][j];
    //     }
    // }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cout << cars[i][j] << "\t";
        cout << endl;
    }
    cout << "\n\n";

    for (int i = 0; i < n; i++)
    {
        if (i < m && i > 0)
            cars[0][i] = 0;
        if (i > m - 1 && i > m)
            cars[0][i] = 0;
    }

    for (j = 0; j < n; j++)
        cout << cars[0][j] << '\t';
    cout << '\n';

    for (i = 1; i < n; i++)
    {
        bool first = true;
        for (int j = 0; j < n; j++)
        {
            bool flag = false;
            int counterY = 0;
            for (int k = 0; k < i; k++)
                if (cars[k][j] != 0)
                    counterY++;
            // if ((j < m && j <= i && (j >= i - 1 - m || m == 1)) || (j >= m && j - m < i + 1 && j >= i))
            // if ((j < m && j <= i && (j + m >= i - 1 || m == 1)) || (j >= m && j - m <= i && j >= i))
            if ((j < m && j <= i && counterY <= n - m) || (j >= m && j - m <= i && j >= i))
            {
                if (j - m >= 0)
                {
                    int k = j - 1;
                    while (cars[i - 1][k] == 0)
                        k--;
                    if (j - m == i)
                        cars[i][j] += cars[i - 1][k];
                    else
                    {
                        if (cars[i - 1][k] < cars[i - 1][j - m - 1] && j - m - 1 >= 0)
                            cars[i][j] += cars[i - 1][j - m - 1];
                        else
                            cars[i][j] += cars[i - 1][k];
                    }
                    flag = true;
                }
                else
                {
                    int k = n - 1;
                    while (cars[i - 1][k] == 0)
                        k--;
                    if (first)
                    {
                        cars[i][j] += cars[i - 1][k];
                        first = false;
                    }
                    else
                    {
                        if (cars[i - 1][k - 1] > cars[i - 1][j - 1])
                            cars[i][j] += cars[i - 1][k - 1];
                        else
                            cars[i][j] += cars[i - 1][j - 1];
                    }
                    flag = true;
                }
                // 4 3 1 1 3 1 1 1 1 1 4 1 1 1 1 2
            }
            if (!flag)
                cars[i][j] = 0;
            cout << cars[i][j] << "\t";
        }
        cout << '\n';
    }

    int max = 0;
    for (i = 0; i < n; i++)
        if (cars[n - 1][i] > max)
            max = cars[n - 1][i];
    cout << "\n\nMAX: " << max << '\n';
}