#include "TreeChar.cpp"
#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

int main()
{
    srand(time(NULL));

    FILE *fTree;

    TreeChar DivName, Name;
    TreeData<int> AllExp, Exp;

    fopen_s(&fTree, "tree", "r");
    inputFileTree(fTree, DivName, Name, AllExp, Exp);

    cout << "\nDivNameTree:\n";
    DivName.Output(DivName.GetHead(), 0);
    cout << "\n\n\nNameTree:\n";
    Name.Output(Name.GetHead(), 0);
    cout << "\n\n\nAllExpTree:\n";
    AllExp.Output(AllExp.GetHead(), 0);
    cout << "\n\n\nExpTree:\n";
    Exp.Output(Exp.GetHead(), 0);

    int choice, temp;
    char tempC[100];
    do
    {
        do
        {
            cout << "\n1. DivName\n2. Name\n3. AllExp\n4. Exp\n0. Exit\nEnter: ";
            cin >> choice;
        } while (choice < 0 || choice > 5);

        switch (choice)
        {
        case 1:
            cout << "Enter divName: ";
            cin >> tempC;
            cout << "RESULT - " << DivName.Search(tempC);
            break;
        case 2:
            cout << "Enter name: ";
            cin >> tempC;
            cout << "RESULT - " << Name.Search(tempC);
            break;
        case 3:
            cout << "Enter allExp: ";
            cin >> temp;
            cout << "RESULT - " << AllExp.Search(temp);
            break;
        case 4:
            cout << "Enter exp: ";
            cin >> temp;
            cout << "RESULT - " << Exp.Search(temp);
            break;
        default:
            break;
        }
    } while (choice > 0 && choice < 5);

    return 0;
}

void inputFileTree(FILE *fTree, TreeChar &divNameTree, TreeChar &NameTree, TreeData<int> &allExpTree, TreeData<int> &expTree)
{
    int nEmployee;
    fscanf(fTree, "%d", &nEmployee);
    char name[100], divName[100];
    int allExp, exp;

    for (int i = 0; i < nEmployee; i++)
    {
        fscanf(fTree, "%s%s%d%d", &divName, &name, &allExp, &exp);
        divNameTree.AddNodeData(divName);
        NameTree.AddNodeData(name);
        allExpTree.AddNodeData(allExp);
        expTree.AddNodeData(exp);
    }
}