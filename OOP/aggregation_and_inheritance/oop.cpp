#include <iostream>

using namespace std;

class A
{
public:
    A()
    {
        cout << "Construct A" << endl;
    }
    ~A()
    {
        cout << "Destruct A" << endl;
    }
};

class B
{
public:
    B()
    {
        cout << "Construct B" << endl;
    }
    ~B()
    {
        cout << "Destruct B" << endl;
    }
};

class C : public A
{
public:
    C()
    {
        cout << "Construct C" << endl;
    }
    ~C()
    {
        cout << "Destruct C" << endl;
    }

    B b;
};


int main()
{
    // Inherited then field then this
    C c; // A B C
    return 0;
}