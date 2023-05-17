//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int size, i, j, n;
    cout << "Enter n: ";
    cin >> n;

    short color[3] = {1, 2, 3};
    bool fuck = false, first;

    for (int t = 0; t < n; t++)
    {
        cout << "Enter size: ";
        cin >> size;
        cout << "Enter block row: ";
        int *block = new int[size];
        for (i = 0; i < size; i++)
            cin >> block[i];

        if (block[0] == 1 || block[0] == 3)
            block[0] = 2;
        else
            block[0] = 3;

        for (i = 1; i < size; i++)
        {
            first = true;
            for (j = 0; j < 3; j++)
            {
                if (i == 1 || i == 2)
                    if (i + 1 == color[j])
                    {
                        fuck = true;
                        continue;
                    }
                if (block[i] == color[j] || block[i - 1] == color[j])
                {
                    fuck = true;
                    continue;
                }
                if (block[i - 1] == block[i] && i > 2)
                {
                    if ((size - i - 1) % 2 == 1)
                    {
                        if (first)
                        {
                            first = false;
                            break;
                        }
                        block[i] = color[j];
                        fuck = false;
                        break;
                    }
                    block[i] = color[j];
                    fuck = false;
                    break;
                }
                block[i] = color[j];
                fuck = false;
                break;
            }
            if (fuck)
                break;
        }
        if (fuck || block[size - 1] == block[0])
        {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for (i = 0; i < size; i++)
            cout << block[i] << " ";
        cout << endl;

        delete[] block;
    }

    return 0;
}
