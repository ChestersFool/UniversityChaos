#include <iostream>
#include "List.cpp"

using namespace std;

int main()
{
    int i, j, k;
    FILE *input;
    fopen_s(&input, "input", "r");

    int amountOfFlowers, amountOfEdges;
    fscanf_s(input, "%d%d", &amountOfFlowers, &amountOfEdges);

    cout << "Amount of Dots - " << amountOfFlowers << "\nAmount of Edges - " << amountOfEdges << endl;

    int **Flowers = new int *[amountOfFlowers];

    for (i = 0; i < amountOfFlowers; i++)
        Flowers[i] = new int[amountOfFlowers];

    for (i = 0; i < amountOfFlowers; i++)
        for (j = 0; j < amountOfFlowers; j++)
            Flowers[i][j] = 0;

    int from, to, power;
    int count = 1, min, max = 6;
    cout << "Enter max: ";
    cin >> max;

    for (i = 0; i < amountOfEdges; i++)
    {
        fscanf_s(input, "%d%d%d", &from, &to, &power);
        Flowers[from - 1][to - 1] = max - power;
        Flowers[to - 1][from - 1] = max - power;
    }
    fclose(input);

    for (i = 0; i < amountOfFlowers; i++)
    {
        for (j = 0; j < amountOfFlowers; j++)
            cout << Flowers[i][j] << " ";

        cout << endl;
    }

    // int count = 1, min, max = 6;
    int point[6], dist[6], from1[6];
    int start = 1;

    // cout << "Enter max: ";
    // cin >> max;

    for (i = 0; i < amountOfFlowers; i++)
        point[i] = 0;

    point[start] = 1;

    for (i = 0; i < amountOfFlowers; i++)
        from1[i] = start;

    from1[start] = 0;

    for (i = 0; i < amountOfFlowers; i++)
    {
        if (Flowers[start][i] != 0)
            dist[i] = Flowers[start][i];
        else
            dist[i] = 0;
    }

    dist[start] = 0;

    // max = 5;

    while (count < amountOfFlowers)
    {
        min = max; // поінт були не були
        for (i = 0; i < amountOfFlowers; i++)
            if (point[i] == 0 && dist[i] < min && dist[i] != 0)
            {
                min = dist[i];
                k = i;
            }
        // min = max - min;
        for (i = 0; i < amountOfFlowers; i++)
        {
            if (i == start)
                continue;
            // перевірка чи я до цього максимуму не дійшов через цю точку
            if (Flowers[k][i] > 0 && dist[i] < dist[k] + Flowers[k][i] && point[i] == 0)
            {
                dist[i] = dist[k] + Flowers[k][i];
                from1[i] = k;
                // break;
            }
        }
        point[k] = 1;
        count++;
    }

    cout << endl
         << endl;
    for (i = 0; i < amountOfFlowers; i++)
        cout << dist[i] << " ";

    cout << endl;

    for (i = 0; i < amountOfFlowers; i++)
        cout << from1[i] << " ";
}