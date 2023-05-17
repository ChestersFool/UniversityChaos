#include <iostream>
#include <cstring>

using namespace std;

int nHeshRow;

class List
{
public:
    List();
    ~List();

    void pushBack(int amount = 0, int data = 0, char bookName[100] = nullptr, char author[100] = nullptr); // ++
    void push(int amount, int data, char bookName[100], char author[100]);

    void popFront();
    void pop(char *bookName);
    void clear();

    void output();
    void outputToFile(FILE *fLibOut);

    int getSize();

    friend void outputFile(FILE *fLibOut, List *lib);

private:
    class node
    {
    public:
        int amount;
        int data;
        char bookName[100];
        char author[100];
        node *pnext;

        node(int amount = 0, int data = 0, char bookName[100] = nullptr, char author[100] = nullptr, node *pnext = nullptr)
        {
            this->amount = amount;
            this->data = data;
            strcpy(this->bookName, bookName);
            strcpy(this->author, author);
            this->pnext = pnext;
        }
    };

    int size;
    node *head;
};

List::List()
{
    size = 0;
    head = nullptr;
}

List::~List()
{
    clear();
}

void List::pushBack(int amount, int data, char bookName[100], char author[100])
{
    if (head == nullptr)
        head = new node(amount, data, bookName, author);
    else
    {
        node *current = this->head;
        while (current->pnext != nullptr)
            current = current->pnext;
        current->pnext = new node(amount, data, bookName, author);
    }
    this->size++;
}

void List::push(int amount, int data, char bookName[100], char author[100])
{
    bool alreadyThere = false;

    node *current = head;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(bookName, current->bookName) == 0)
        {
            alreadyThere = true;
            break;
        }

        current = current->pnext;
    }
    if (alreadyThere)
        current->amount += amount;
    else
        pushBack(amount, data, bookName, author);
}

void List::popFront()
{
    node *temp = head;
    head = head->pnext;
    delete temp;
    size--;
}

void List::pop(char *bookName)
{
    if (head == nullptr)
        return;
    else if (strcmp(bookName, head->bookName) == 0)
    {
        if (head->amount > 1)
            head->amount--;
        else
            popFront();
    }
    else
    {
        node *current = this->head;
        bool alreadyThere = false;

        while (current->pnext != nullptr)
        {
            if (strcmp(bookName, current->pnext->bookName) == 0)
            {
                alreadyThere = true;
                break;
            }
            current = current->pnext;
        }

        if (alreadyThere)
        {
            if (current->pnext->amount > 1)
                current->pnext->amount--;
            else
            {
                node *temp = current->pnext;
                current->pnext = current->pnext->pnext;
                delete temp;
                this->size--;
            }
        }
    }
}

void List::clear()
{
    while (size)
        popFront();
}

void List::output()
{
    cout << "\n------------\n";
    node *current = head;
    for (int j = 0; j < size; j++)
    {
        cout << current->bookName << "(" << current->amount << ")"
             << "\t";

        current = current->pnext;
    }
}

void List::outputToFile(FILE *fLibOut)
{
    node *current = head;

    for (int i = 0; i < size; i++)
    {
        fprintf(fLibOut, "%d %d %s %s\n", current->amount, current->data, current->bookName, current->author);
        current = current->pnext;
    }
}

int List::getSize()
{
    return this->size;
}

void outputFile(FILE *fLibOut, List *lib)
{
    int nBook = 0;
    for (int i = 0; i < nHeshRow; i++)
        nBook += lib[i].size;
    fprintf(fLibOut, "%d\n", nBook);
}

int heshKey(int);

void inputFileLib(FILE *fLib, List *&lib);

int sumASCII(char *string);

int main()
{
    List *lib = nullptr;
    FILE *fLib, *fLibOut;

    fopen_s(&fLib, "lib", "r");
    inputFileLib(fLib, lib);
    fclose(fLib);

    int choice;
    do
    {
        char bookName[100];
        char bookAuthor[100];
        int bookYear;
        int amount;
        do
        {
            cout << "\n1. Output table\n2. Delete book\n3. Add book\n4. Restruct\n0. Exit\nEnter: ";
            cin >> choice;
        } while (choice < 0 || choice > 4);

        switch (choice)
        {
        case 1:
            for (int i = 0; i < nHeshRow; i++)
                lib[i].output();
            break;
        case 2:
            cout << "Enter book name: ";
            cin >> bookName;

            lib[heshKey(sumASCII(bookName))].pop(bookName);
            break;
        case 3:
            cout << "Enter book name: ";
            cin >> bookName;
            cout << "Enter book`s author: ";
            cin >> bookAuthor;
            cout << "Enter book year: ";
            cin >> bookYear;
            cout << "Enter amount of book/s: ";
            cin >> amount;

            lib[heshKey(sumASCII(bookName))].push(amount, bookYear, bookName, bookAuthor);
            break;
        case 4:
            fopen_s(&fLibOut, "libout", "w");
            outputFile(fLibOut, lib);
            for (int i = 0; i < nHeshRow; i++)
                lib[i].outputToFile(fLibOut);
            fclose(fLibOut);

            delete[] lib;
            lib = nullptr;

            fopen_s(&fLibOut, "libout", "r");
            inputFileLib(fLibOut, lib);
            fclose(fLib);
            break;
        default:
            break;
        }
    } while (choice > 0 && choice < 5);

    // cout << "1.\n";
    // for (int i = 0; i < nHeshRow; i++)
    //     lib[i].output();

    // char *bookName = new char[5]{"Math"};
    // lib[heshKey(sumASCII(bookName))].pop(bookName);

    // strcpy(bookName, "History4");
    // char *author = new char[6]{"Janyk"};
    // lib[heshKey(sumASCII(bookName))].push(3, 1993, bookName, author);

    // strcpy(bookName, "Chemistry");
    // strcpy(author, "Cicha");
    // lib[heshKey(sumASCII(bookName))].push(1, 999, bookName, author);

    // strcpy(bookName, "Chem");
    // strcpy(author, "One");
    // lib[heshKey(sumASCII(bookName))].push(3, 3000, bookName, author);

    // fopen_s(&fLib, "lib", "r");
    // inputFileLib(fLib, lib);
    // fclose(fLib);

    // cout << "\n2.\n";
    // for (int i = 0; i < nHeshRow; i++)
    //     lib[i].output();

    // for (int i = 0; i < nHeshRow; i++)
    //     lib[i].~List();
    // lib = nullptr;

    return 0;
}

int heshKey(int key)
{
    return key % nHeshRow;
}

void inputFileLib(FILE *fLib, List *&lib)
{
    int nBook;
    fscanf(fLib, "%d", &nBook);

    if (lib == nullptr)
    {
        if (nBook % 4 == 0)
            nHeshRow = nBook / 4;
        else
            nHeshRow = (nBook / 4) + 1;

        lib = new List[nHeshRow];
    }

    int amount, data;
    char bookName[100], author[100];

    for (int i = 0; i < nBook; i++)
    {
        fscanf(fLib, "%d%d%s%s", &amount, &data, &bookName, &author);
        lib[heshKey(sumASCII(bookName))].push(amount, data, bookName, author);
    }
}

int sumASCII(char *string)
{
    int i = 0, sumASCI = 0;
    while (string[i] != '\0')
        sumASCI += string[i++];

    return sumASCI;
}