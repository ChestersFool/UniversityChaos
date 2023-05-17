#include <iostream>

using namespace std;

class base
{
    int a, b;
    public:
    //
    base()
    {
        cout << "base";
    }
    virtual void calc() = 0;
};

class son : public base
{
public:
    son(){
        cout << "son";
    }
    virtual void calc()
    {
        cout << "soncalc";
    }
};

int main()
{
    //base a;
    //son b;
    base *a;
    son b;
    a = &b;
    a->calc();
}