#include <iostream>
#include "Queue.cpp"
#include "List.cpp"

using namespace std;

int main()
{
    int i, j;
    FILE *input;
    fopen_s(&input, "input", "r");

    int amountOfStations, amountOfRoads;
    fscanf_s(input, "%d%d", &amountOfStations, &amountOfRoads);

    cout << "Amount of Stations - " << amountOfStations << "\nAmount of Roads - " << amountOfRoads << endl;

    List *pMetroList = new List[amountOfStations];
    int from, to;
    for (i = 0; i < amountOfRoads; i++)
    {
        fscanf_s(input, "%d%d", &from, &to);
        pMetroList[from - 1].PushBack(to);
        pMetroList[to - 1].PushBack(from);
    }

    fclose(input);

    for (i = 0; i < amountOfStations; i++)
    {
        cout << i + 1 << '\t';
        pMetroList[i].Output();
        cout << endl;
    }

    Queue metroQueue(amountOfStations);
    bool *wasThere = new bool[amountOfStations];

    for (i = 0; i < amountOfStations; i++)
        wasThere[i] = false;

    bool found = false;
    int searched, currentIndex, nextStation;

    cout << "Enter searched: ";
    cin >> searched;

    metroQueue.Push(1, 0);

    for (i = 0; i <= amountOfStations && metroQueue.Size() != 0; i++)
    {
        currentIndex = metroQueue.Pop() - 1;
        wasThere[currentIndex] = true;

        while (pMetroList[currentIndex].GetSize() != 0)
        {
            nextStation = pMetroList[currentIndex].PopFront();

            if (wasThere[nextStation - 1])
                continue;

            metroQueue.Push(nextStation, currentIndex + 1);

            if (nextStation == searched)
            {
                found = true;
                break;
            }
        }
        if (found)
            break;
    }

    if (!found)
    {
        cout << "The way isn`t found!" << endl;
        return 1;
    }

    cout << "The way is found!" << endl;

    i = metroQueue.GetTail() - 1;

    while (metroQueue[i] != 0)
    {
        cout << metroQueue[i] << " ";
        i = metroQueue.GetIndexFrom(i);
    }

    return 0;
}