#include <iostream>
#include "AString.h"
#include "AString.cpp"

using namespace std;

class PAString : public AString
{
protected:
    static int _SId;
    int _Id;
    AString _PAStrigName;

public:
    PAString();
    PAString(const char *PAStringName, const char *outherPChar);
    PAString(const PAString &OutherPAStirng);
    ~PAString() = default;

    void Input();

    void Output() const;

    void AStringToUpperCase();

    void AStringToLowerCase();

    int Compare(const PAString &OutherPAString) const;

    (*operator char() const);

    (*operator int() const);

    PAString &operator+=(const PAString &OutherPAString);

    PAString &operator=(PAString &OutherPAString);

    char &operator[](int index);

    friend ostream &operator<<(ostream &out, const PAString &current);

    friend istream &operator>>(istream &in, PAString &current);
};

int PAString::_SId = 1;

PAString::PAString() //, _PAStrigName() //: AString()
{
    cout << "Builder(PPASTRING) -" << this << "\n";
    this->_Id = _SId++;
}

PAString::PAString(const char *PAStringName, const char *outherPChar) : _PAStrigName(PAStringName), AString(outherPChar)
{
    cout << "Builder(PPASTRING) -" << this << "\n";
    this->_Id = _SId++;
}

PAString::PAString(const PAString &OutherPAStirng) : _PAStrigName(OutherPAStirng._PAStrigName), AString(OutherPAStirng)
{
    cout << "COPY Builder(PPASTRING) -" << this << "\n";
    this->_Id = _SId++;
}

void PAString::Input()
{
    char buffer[101];

    cout << "Enter string name (to 100 symbols): ";
    cin >> buffer;
    this->_PAStrigName.Copy(buffer);

    cout << "Enter string (to 100 symbols): ";
    cin >> buffer;
    // Copy(buffer);
    this->Copy(buffer);
    // this->AString::Copy(buffer);
    // AString::Copy(buffer);
}
//Бог зна що там собі думає кампілятор
//Але ці два записи рівносильні

void PAString::Output() const
{
    cout << "NAME - ";
    this->_PAStrigName.Output();

    cout << "\nASTRING - ";
    // Output(); //А тут вже дічь повна і воно вже іде в рекурсію
    // this->Output(); //А тут вже дічь повна і воно вже іде в рекурсію
    // this->AString::Output(); // Це можна
    AString::Output();

    cout << endl
         << "ID - " << this->_Id;
}

void PAString::AStringToUpperCase()
{
    int i = 0, charToInt;

    while (this->_PChar[i] != '\0')
    {
        charToInt = this->_PChar[i];

        if (charToInt > 96 && charToInt < 123)
            this->_PChar[i] = charToInt - 32;

        i++;
    }
}

void PAString::AStringToLowerCase()
{
    int i = 0, charToInt;

    while (this->_PChar[i] != '\0')
    {
        charToInt = this->_PChar[i];

        if (charToInt > 64 && charToInt < 91)
            this->_PChar[i] = charToInt + 32;

        i++;
    }
}

(*PAString::operator char() const)
{
    int pCharSize = this->Size();
    char *pChar = new char[pCharSize];
    int i = 0;

    for (; i < pCharSize; i++)
        pChar[i] = _PChar[i];

    pChar[i] = '\0';

    return pChar;
}

(*PAString::operator int() const)
{
    int pIntSize = this->Size();
    int *pInt = new int[pIntSize + 1];

    for (int i = 0; i < pIntSize; i++)
        pInt[i] = _PChar[i];

    return pInt;
}

PAString &PAString::operator+=(const PAString &OutherPAString)
{
    int sizeThis = this->Size();
    int sizeOuther = OutherPAString.Size();

    char *temp = new char[sizeThis + sizeOuther + 1];
    int i;

    for (i = 0; i < sizeThis; i++)
        temp[i] = this->_PChar[i];

    for (int j = 0; i < sizeThis + sizeOuther; i++, j++)
        temp[i] = OutherPAString._PChar[j];

    temp[i] = '\0';
    this->Copy(temp);

    return *this;
}

PAString &PAString::operator=(PAString &OutherPAString)
{
    if (this == &OutherPAString)
        return *this;

    this->_PAStrigName = OutherPAString._PAStrigName;

    this->AString::operator=(OutherPAString); // +
    //(AString)*this = (AString)OutherPAString; // -

    return *this;
}

char &PAString::operator[](int index)
{
    return this->_PChar[index];
}

ostream &operator<<(ostream &out, const PAString &current)
{
    out << "NAME: " << current._PAStrigName.Get_PChar() << "; STR: " << current._PChar << "; ID: " << current._Id;
    // out << "NAME: " << current._PAStrigName._PChar << "; STR: " << current._PChar << "; ID: " << current._Id;
    return out;
}

istream &operator>>(istream &in, PAString &current)
{
    char buffer[101];

    cout << "Enter string name (to 100 symbols): ";
    in >> buffer;
    current._PAStrigName.Copy(buffer);

    cout << "Enter string (to 100 symbols): ";
    in >> buffer;
    current.Copy(buffer);
    return in;
}

int PAString::Compare(const PAString &OutherPAString) const
{
    int sizeThis = this->Size();
    int sizeOuther = OutherPAString.Size();
    int i = 0;

    while (this->_PChar[i] != '\0' && OutherPAString._PChar[i] != '\0')
    {
        if (this->_PChar[i] != OutherPAString._PChar[i])
            return this->_PChar[i] - OutherPAString._PChar[i];

        i++;
    }

    if (sizeThis == sizeOuther)
        return 0;

    if (i == sizeThis)
        return -int(OutherPAString._PChar[i]);

    return int(this->_PChar[i]);
}

int main()
{
    // system("color 04");
    // {
    //     PAString x("first", "abc"), y("second", "123");
    //     x += y;
    //     cout << "x += y; " << x << endl;
    // }
    PAString a("first", "asbz1");
    cout << a;
    // {
    //     PAString c;
    //     PAString b = a;
    //     cout << "PAString b(a); " << b << endl;
    //     b[2] = '0';
    // }
    // cout << "Did a chanced? " << a << endl;
    // {
    //     PAString x("1", "123"), y("2", "1234");
    //     cout << "x.Compare(y) - " << x.Compare(y) << endl;
    // }
    // {
    //     PAString b;
    //     b = a;
    //     cout << "b = a; " << b << endl;
    //     b[2] = '0';
    // }
    // cout << "Did a chanced? " << a << endl;
    // {
    //     cin >> a;
    //     a.Output();
    //     cout << endl;
    //     a.Input();
    //     cout << a << endl;
    // }
    // {
    //     a[2] = 'e';
    //     cout << "a[2] = 'e'; " << a << endl;
    // }
    // {
    //     char *test;
    //     test = a;
    //     cout << "char*(a); " << test << endl;
    //     test[2] = 'n';
    //     // delete[] test;
    // }
    // cout << "Did a chanced? " << a << endl;
    // {
    //     int *test1;
    //     test1 = a;

    //     for (int i = 0; i < a.Size(); i++)
    //         cout << test1[i] << " ";

    //     test1[2] = 2;
    //     delete[] test1;
    // }
    // cout << "\nDid a chanced? " << a << endl;
    // {
    //     a.AStringToUpperCase();
    //     cout << a << endl;
    //     a.AStringToLowerCase();
    //     cout << a << endl;
    // }
    return 0;
}