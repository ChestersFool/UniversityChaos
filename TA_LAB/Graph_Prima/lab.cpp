#include <iostream>
#include "List.cpp"

using namespace std;

int main()
{
    int i, j;
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


    int pensils;

    cout << "How many pencils does the boy have? ";
    cin >> pensils;

    bool *wasThere = new bool[amountOfDots];

    for (i = 0; i < amountOfDots; i++)
        wasThere[i] = false;

    int currentIndex, nextDot, head = 0;
    int *stack = new int[amountOfDots];

    for (i = 1; i < amountOfDots; i++)
        stack[i] = 0;

    stack[head++] = 1;

    int k;
    i = 0;
    do
    {
        currentIndex = stack[head - 1] - 1;

        k = 2; // k = 1 ?
        if (pDotsList[currentIndex].GetSize() == 0)
        {
            pensils--;
            while (pDotsList[currentIndex].GetSize() == 0 && head - k >= 0)
                currentIndex = stack[head - k++] - 1;
        }

        wasThere[currentIndex] = true;
        while (pDotsList[currentIndex].GetSize() != 0)
        {
            nextDot = pDotsList[currentIndex].PopFront();

            if (wasThere[nextDot - 1])
                continue;

            pDotsListNew[currentIndex].PushBack(nextDot);

            stack[head] = nextDot;
            head++;
            i++;
            break;
        }
    } while (head != amountOfDots && !(currentIndex == 0 && pDotsList[0].GetSize() == 0));


    if (head == amountOfDots)
    {
        if (pensils <= 0)
        {
            cout << "The boy didn't have enough pencils, he is cries! You`r bad father!";
            return 1;
        }

        cout << "Yes, the boy has " << pensils << " pencils left" << endl;
        for (i = 0; i < amountOfDots; i++)
        {
            cout << i + 1 << '\t';
            pDotsListNew[i].Output();
            cout << endl;
        }
    }
    else
        cout << "NO";
}
