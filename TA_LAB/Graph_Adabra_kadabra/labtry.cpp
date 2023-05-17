#include <iostream>
#include "List.cpp"

using namespace std;

void Gamilton(List *pClassroomList, List *pClassroomNeighborhood, bool *wasThere, int &currentClassroom, int &amountOfClassrooms, int &i, int *stack, int &head, int &k, int &pensils, int &maxPensils)
{
    if (i == amountOfClassrooms - 1 && pensils == maxPensils)
    {
        stack[head] = currentClassroom;
        return;
    }

    if (!wasThere[currentClassroom])
    {
        wasThere[currentClassroom] = true;

        stack[head] = currentClassroom;
        head++;

        pClassroomNeighborhood[currentClassroom] = pClassroomList[currentClassroom];
    }

    int nextClassroom;
    while (pClassroomNeighborhood[currentClassroom].GetSize() != 0)
    {
        nextClassroom = pClassroomNeighborhood[currentClassroom].PopFront() - 1;

        if (!wasThere[nextClassroom] && i != amountOfClassrooms - 1)
        {
            i++;
            Gamilton(pClassroomList, pClassroomNeighborhood, wasThere, nextClassroom, amountOfClassrooms, i, stack, head, k, pensils, maxPensils);
        }
    }

    if (i == amountOfClassrooms - 1 && pensils == maxPensils)
        return;

    if (pClassroomNeighborhood[currentClassroom].GetSize() == 0)
    {
        k = 2; // k = 2;
        pensils--;
        do
        {
            nextClassroom = stack[head - k++]; // +1 for dot name
        } while (pClassroomNeighborhood[nextClassroom].GetSize() == 0 && head - k >= 0);

        if (pClassroomNeighborhood[nextClassroom].GetSize() != 0)
            Gamilton(pClassroomList, pClassroomNeighborhood, wasThere, nextClassroom, amountOfClassrooms, i, stack, head, k, pensils, maxPensils);
    }

    if (i == amountOfClassrooms - 1 && pensils == maxPensils)
        return;

    wasThere[currentClassroom] = false;
    i--;
    head--;
    pensils = maxPensils;
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

    List *pClassroomNeighborhood = new List[amountOfClassrooms];
    bool *wasThere = new bool[amountOfClassrooms];

    for (i = 0; i < amountOfClassrooms; i++)
        wasThere[i] = false;

    i = 0;
    int currentClassroom = 0, head = 0, k = 2, maxPensils = amountOfClassrooms + 2, pensils = maxPensils;
    int *stack = new int[amountOfClassrooms];

    for (i = 0; i < amountOfClassrooms; i++)
        stack[i] = -1;

    i = 0;
    Gamilton(pClassroomList, pClassroomNeighborhood, wasThere, currentClassroom, amountOfClassrooms, i, stack, head, k, pensils, maxPensils);

    if (i == amountOfClassrooms - 1)
        cout << "\nYES";
    else
        cout << "NO";

    cout << endl;
    for (i = 0; i < amountOfClassrooms; i++)
        cout << stack[i] + 1 << " ";
}
