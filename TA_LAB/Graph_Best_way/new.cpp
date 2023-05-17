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
            Flowers[i][j] = 650000;

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

    for (k = 0; k < amountOfFlowers; k++)
        for (i = 0; i < amountOfFlowers; i++)
            for (j = 0; j < amountOfFlowers; j++)
                if (Flowers[i][k] + Flowers[k][j] < Flowers[i][j])
                    Flowers[i][j] = Flowers[i][k] + Flowers[k][j];

    cout << "\n\n\n";

    for (i = 0; i < amountOfFlowers; i++)
    {
        for (j = 0; j < amountOfFlowers; j++)
            cout << Flowers[i][j] << " ";

        cout << endl;
    }
}

// FIXME Бог зна чи працює
// TODO Узнати чи працює