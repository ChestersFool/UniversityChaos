#include <iostream>
#include <cmath>
#include <vector>

using std::cout, std::cin, std::vector;

double distance(const int &x1, const int &y1, const int &x2, const int &y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double angular_coef(const int &x1, const int &y1, const int &x2, const int &y2)
{
    return (y2 - y1) / double(x2 - x1);
}

int main()
{
    // * 1
    // vector<int> x = {0, 0, 1, 3, 0, 3};
    // vector<int> y = {0, 3, 2, 3, 4, 5};
    // * 2
    vector<int> x = {0, 3, 1, 3, 3, 5};
    vector<int> y = {0, 0, 2, 1, -1, 0};
    int first_x, first_y, n, counter = 0;
    // vector<int> x, y;
    // cout << "Enter n: ";
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i + 1 << ": ";
    //     cin >> first_x >> first_y;
    //     x.push_back(first_x);
    //     y.push_back(first_y);
    // }

    while (x.size() > 0)
    {
        first_x = x[0];
        first_y = y[0];
        for (int i = 1; i < x.size(); i++)
        {
            if (y[i] < first_y && first_x == x[i])
                first_y = y[i];
            if (x[i] < first_x)
            {
                first_x = x[i];
                first_y = y[i];
            }
        }
        cout << "Point: " << first_x << ',' << first_y << '\n';
        for (int i = 0; i < x.size();)
        {
            // cout << "Kut mizh tochkou " << first_x << ',' << first_y << " i " << x[i] << ',' << y[i] << ": " << angular_coef(first_x, first_y, x[i], y[i]) << '\n';
            if (distance(first_x, first_y, x[i], y[i]) <= 3)
            {
                cout << x[i] << ',' << y[i] << '\t';
                x.erase(x.begin() + i);
                y.erase(y.begin() + i);
                continue;
            }
            i++;
        }
        cout << '\n';
        counter++;
    }

    cout << "You need " << counter << " gifts!\n";
    return 0;
}