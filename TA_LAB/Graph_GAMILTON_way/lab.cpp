#include <iostream>
#include "List.cpp"

using namespace std;

void Gamilton(List *pClassroomList, List *pClassroomNeighborhood, bool *wasThere, int &currentClassroom, int &to, int &amountOfClassrooms, int &i)
{
    if (currentClassroom == to - 1 && i == amountOfClassrooms - 1)
    {
        cout << to << " ";
        return;
    }

    if (currentClassroom == to - 1)
    {
        i--;
        return;
    }

    wasThere[currentClassroom] = true;
    pClassroomNeighborhood[currentClassroom] = pClassroomList[currentClassroom];

    int nextClassroom;
    while (pClassroomNeighborhood[currentClassroom].GetSize() != 0)
    {
        nextClassroom = pClassroomNeighborhood[currentClassroom].PopFront() - 1;

        if (!wasThere[nextClassroom] && i != amountOfClassrooms - 1)
        {
            i++;
            Gamilton(pClassroomList, pClassroomNeighborhood, wasThere, nextClassroom, to, amountOfClassrooms, i);
        }
    }

    if (i == amountOfClassrooms - 1)
    {
        cout << currentClassroom + 1 << " ";
        return;
    }

    wasThere[currentClassroom] = false;
    i--;
    return;
}

int main()
{
    int i, j;
    FILE *input;
    fopen_s(&input, "input", "r");

    int amountOfClassrooms, amountOfRoads;
    fscanf_s(input, "%d%d", &amountOfClassrooms, &amountOfRoads);

    cout << "Amount of Classrooms - " << amountOfClassrooms << "\nAmount of Roads - " << amountOfRoads << endl;

    List *pClassroomList = new List[amountOfClassrooms];
    int from, to;
    for (i = 0; i < amountOfRoads; i++)
    {
        fscanf_s(input, "%d%d", &from, &to);
        pClassroomList[from - 1].PushBack(to);
        pClassroomList[to - 1].PushBack(from);
    }

    fclose(input);

    for (i = 0; i < amountOfClassrooms; i++)
    {
        cout << i + 1 << '\t';
        pClassroomList[i].Output();
        cout << endl;
    }

    cout << "Enter from which classroom: ";
    cin >> from;
    cout << "Enter to which classroom: ";
    cin >> to;

    List *pClassroomNeighborhood = new List[amountOfClassrooms];
    bool *wasThere = new bool[amountOfClassrooms];

    for (i = 0; i < amountOfClassrooms; i++)
        wasThere[i] = false;

    i = 0;
    int currentClassroom = from - 1;

    Gamilton(pClassroomList, pClassroomNeighborhood, wasThere, currentClassroom, to, amountOfClassrooms, i);
    
    if (i == amountOfClassrooms - 1)
        cout << "\nYES";
    else
        cout << "NO";
}
