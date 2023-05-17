#include "Array.cpp"

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5};

    Array<int> first(arr, sizeof(arr));
    first.Output();

    Array<int> second(first);
    second.Output();

    Array<int> third;
    third.Input();
    third.Output();
    return 0;
}