#include <iostream>
#include <ctime>

using namespace std;

struct Tree
{
    int data;
    Tree *left, *right;
};

void add_node_tree(Tree *, int);

void print_Tree(Tree *, int);

void calc_max_length_Tree(Tree *, int, int &);

void delete_Tree(Tree *);

int main()
{
    srand(time(NULL));
    Tree first;
    Tree *x = &first;

    int temp;
    for (int i = 0; i < 10; i++)
    {
        temp = rand() % 10 + 1;
        cout << temp << " ";
        add_node_tree(x, temp);
    }

    cout << "\nPRINT TREE:";
    print_Tree(x, 0);

    int max;
    calc_max_length_Tree(x, 1, max);
    cout << "\nMAX LENGHT - " << max;

    delete_Tree(x);
    return 0;
}

void add_node_tree(Tree *ptree, int value)
{
    if (ptree == nullptr)
    {
        ptree = new Tree;
        ptree->data = NULL;
    }

    while (ptree->data != NULL)
    {
        if (value > ptree->data)
        {
            if (ptree->right == nullptr)
            {
                ptree->right = new Tree;
                ptree->right->data = NULL;
            }
            ptree = ptree->right;
        }

        if (value <= ptree->data)
        {
            if (ptree->left == nullptr)
            {
                ptree->left = new Tree;
                ptree->left->data = NULL;
            }
            ptree = ptree->left;
        }
    }
    ptree->data = value;
    ptree->left = nullptr;
    ptree->right = nullptr;
}

void print_Tree(Tree *ptree, int tab)
{
    if (ptree != nullptr)
    {
        print_Tree(ptree->right, tab + 1);
        cout << endl;
        for (int i = 0; i < tab; i++)
            cout << "       ";

        cout << ptree->data;
        print_Tree(ptree->left, tab + 1);
    }
}

void calc_max_length_Tree(Tree *ptree, int tab, int &max)
{
    if (ptree != nullptr)
    {
        if (tab > max)
            max = tab;
        calc_max_length_Tree(ptree->right, tab + 1, max);
        calc_max_length_Tree(ptree->left, tab + 1, max);
    }
}

void delete_Tree(Tree *ptree)
{
    if (ptree != nullptr)
    {
        delete_Tree(ptree->right);
        delete_Tree(ptree->left);
        delete ptree;
    }
}