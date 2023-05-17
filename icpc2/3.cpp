#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, nArr, res, j, k;
    int *arr;
    cin >> n;
    bool flag;
    for (int i = 0; i < n; i++)
    {
        cin >> nArr;
        arr = new int[nArr];
        for (j = 0; j < nArr; j++)
            cin >> arr[j];

        for (k = 0; k < nArr - 1; k++)
        {
            for (int y = k + 1; y < nArr; y++)
            {
                res = abs(arr[k] - arr[y]);

                flag = true;
                for (j = 0; j < nArr; j++)
                {
                    if (arr[j] == res)
                    {
                        flag = false;
                        break;
                    }
                }

                if (flag)
                    continue;

                if(!flag)
                    break;
            }
            if (flag)
                break;
        }
        cout << arr[k] << endl;
        delete[] arr;
    }
}
