#include "AString.cpp"
#include <iostream>

using namespace std;

int main()
{
    AString a;
    AString b("zt");
    AString c(b);

    // a.Input();
    // cout << "a - ";
    // a.Output();
    // cout << endl;

    cout << "b - ";
    b.Output();
    cout << endl;

    cout << "c - ";
    c.Output();
    cout << endl;

    // c.Copy("abcdefg");
    // cout << "c after copy - ";
    // c.Output();
    // cout << endl;

    // c.DeleteNElmentsFromPoz(100, 5);
    // cout << "c after DeleteNElmentsFromPoz(100, 5) - ";
    // c.Output();
    // cout << endl;

    // c.DeleteNElmentsFromPoz(2, 1);
    // cout << "c after DeleteNElmentsFromPoz(2, 1) - ";
    // c.Output();
    // cout << endl;

    // c.StringInsertionFromPoz(b, 2);
    // cout << "c after StringInsertionFromPoz(b, 2) - ";
    // c.Output();
    // cout << " size of c - " << c.Size() << endl;

    // AString d(substringNFromPoz(c, 3, 2));
    // cout << "substringNFromPoz(c, 3, 2) - ";
    // d.Output();
    // cout << " size of d - " << d.Size() << " first enter of d in c - " << firstEnterSubstringInString(c, d) << "(elem)" << endl;

    // AString g("1234567890");
    // cout << "g - ";
    // g.Output();
    // cout << "\ng is int? - " << stringIsInt(g) << endl;
    // cout << stringToInt(g) + 1 << endl;

    // g.Copy("12.3");
    // cout << "g - ";
    // g.Output();
    // cout << "\ng is int? - " << stringIsInt(g) << endl;
    // cout << stringToInt(g) << endl;

    AString x, y;
    cout << "Input x - ";
    x.Input();
    cout << "Input y - ";
    y.Input();

    x.Output();
    cout << " * ";
    y.Output();
    cout << " = ";
    AString z;
    z = x * y;
    z.Output();
    cout << endl;

    x.Output();
    cout << " + ";
    y.Output();
    cout << " = ";
    z = x + y;
    z.Output();
    cout << endl;

    x.Output();
    cout << " == ";
    y.Output();
    cout << " = ";
    cout << (x == y) << endl;

    x.Output();
    cout << " != ";
    y.Output();
    cout << " = ";
    cout << (x != y) << endl;

    x.Output();
    cout << " <= ";
    y.Output();
    cout << " = ";
    cout << (x <= y) << endl;

    x.Output();
    cout << " > ";
    y.Output();
    cout << " = ";
    cout << (x > y) << endl;

    x.Output();
    cout << " >= ";
    y.Output();
    cout << " = ";
    cout << (x >= y) << endl;

    x.Output();
    cout << " < ";
    y.Output();
    cout << " = ";
    cout << (x < y) << endl;
}