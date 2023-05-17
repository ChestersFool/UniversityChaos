#include <iostream>
#include "List.cpp"

using namespace std;

int main()
{
    int i, j, k;
    FILE *input;
    fopen_s(&input, "input", "r");

    int amountOfDots, amountOfEdges;
    fscanf_s(input, "%d%d", &amountOfDots, &amountOfEdges);

    cout << "Amount of Dots - " << amountOfDots << "\nAmount of Edges - " << amountOfEdges << endl;

    List *pDotsList = new List[amountOfDots];
    List *pDotsListNew = new List[amountOfDots];
    int from, to;
    for (i = 0; i < amountOfEdges; i++)
    {
        fscanf_s(input, "%d%d", &from, &to);
        pDotsList[from - 1].PushBack(to);
        pDotsList[to - 1].PushBack(from);
    }

    fclose(input);

    for (i = 0; i < amountOfDots; i++)
    {
        cout << i + 1 << '\t';
        pDotsList[i].Output();
        cout << endl;
    }

    int *inMyColor = new int[amountOfDots];

    for (i = 0; i < amountOfDots; i++)
        inMyColor[i] = i + 1;

    int currentIndex, nextDot, colorToChange, sumOfEdges, maxOfEdges, pensils;

    cout << "How many pensils boy has? ";
    cin >> pensils;

    i = 0;

    while (i != amountOfDots - 1)
    {
        maxOfEdges = 0;
        for (j = 0; j < amountOfDots; j++)
        {
            sumOfEdges = pDotsList[j].GetSize();
            if (sumOfEdges > maxOfEdges)
            {
                maxOfEdges = sumOfEdges;
                currentIndex = j;
            }
        }

        pensils--;

        while (pDotsList[currentIndex].GetSize() != 0 && i != amountOfDots - 1)
        {
            nextDot = pDotsList[currentIndex].PopFront();
            pDotsList[nextDot - 1].Pop(currentIndex + 1);

            if (inMyColor[nextDot - 1] == currentIndex + 1)
                continue;

            pDotsListNew[currentIndex].PushBack(nextDot);
            // pDotsListNew[nextDot - 1].PushBack(currentIndex + 1);

            if (inMyColor[nextDot - 1] != 0)
            {
                colorToChange = inMyColor[nextDot - 1];

                for (int k = 0; k < amountOfDots; k++)
                    if (inMyColor[k] == colorToChange)
                        inMyColor[k] = inMyColor[currentIndex];

                i++;
                continue;
            }
            inMyColor[nextDot - 1] = currentIndex + 1;
            i++;
        }
    }

    if (i != amountOfDots - 1)
    {
        cout << "No way!";
        return 1;
    }

    if (pensils < 0)
    {
        cout << "Boy has`t got enought pensils!";
        return 1;
    }

    for (i = 0; i < amountOfDots; i++)
        cout << i + 1 << "(" << inMyColor[i] << ") ";

    cout << "\nNow boy has " << pensils << " pensils." << endl;
    cout << "NEW: " << endl;

    for (i = 0; i < amountOfDots; i++)
    {
        cout << i + 1 << '\t';
        pDotsListNew[i].Output();
        cout << endl;
    }
}
