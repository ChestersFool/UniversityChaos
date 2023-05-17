#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x, y, i, j;
    cin >> n;

    for (int k = 0; k < n; k++)
    {
        cin >> x >> y;

        int steps = 0, xx = abs(x), yy = abs(y);

        if (xx > yy)
            steps = yy;
        else
            steps = xx;
        i = j = steps;

        if (x < 0)
            i = -i;
        if (y < 0)
            j = -j;

        x = x - i;
        y = y - j;
        xx = abs(x), yy = abs(y);

        if (y == 0)
        {
            if (xx % 2 == 0)
            {
                steps += xx;
                x = 0;
            }

            else if (xx % 2 == 1)
            {
                steps += xx + 1;
                x = 0;
            }
        }

        if (x == 0)
        {
            if (y > 0)
            {
                steps += yy;
                y = 0;
            }
            else if (y % 2 == 0)
            {
                steps += yy;
                y = 0;
            }
            else if (y % 2 == -1)
            {
                steps += yy + 2;
                y = 0;
            }
        }

        cout << steps << endl;
    }
}
