#include <iostream>

using namespace std;

class A
{
public:
    void Use()
    {
        cout << "a" << endl;
    }
};

class B
{
public:
    void Use()
    {
        cout << "b" << endl;
    }
};

class C : public A, public B
{
};

int main()
{
    C c;
    c.B::Use();
    ((B)c).Use();

    return 0;
}