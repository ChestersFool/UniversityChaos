#include <cstdlib>
#include <iostream>
#include <fstream>
#include <set>
using namespace std;

set<int> s, s1;
int main(int argc, char *argv[])
{
    int d[100][100];
    int dist[100];
    int from[100];
    int n, m, k, i, j, st, fin, min, x, y, w;
    ifstream f_in("in_d.dat");
    ofstream f_out("out_d.sol");
    f_in >> n >> m;
    f_in >> st >> fin;
    for (i = 0; i < n; i++)
    {
        for (j = 1; j <= n; j++)
            d[i][j] = 0;
    }
    for (i = 0; i < m; i++)
    {
        f_in >> x >> y >> w;
        d[x][y] = w;
        d[y][x] = w;
    }
    for (i = 0; i < n; i++)
        s.insert(i);
    s.erase(st);
    for (i = 0; i < n; i++)
    {
        if (d[st][i] == 0)
            dist[i] = 65535;
        else
            dist[i] = d[st][i];
        from[i] = st;
    }
    from[st] = 0;
    dist[st] = 0;
    while (s != s1)
    {
        min = 65535;
        for (i = 0; i < n; i++)
        {
            if (s.find(i) != s.end() && dist[i] < min && dist[i] > 0)
            {
                min = dist[i];
                k = i;
            }
        }
        for (i = 0; i < n; i++)
        {
            if (d[k][i] > 0 && dist[i] > dist[k] + d[k][i])
            {
                dist[i] = dist[k] + d[k][i];
                from[i] = k;
            }
        }
        s.erase(k);
    }
    i = fin;
    f_out << dist[fin] << "\n";
    f_out << fin << " ";
    while (i != st)
    {
        f_out << from[i] << " ";
        i = from[i];
    }
    f_out.close();
    system("PAUSE");
    return EXIT_SUCCESS;
}
