#pragma once
#include <iostream>

using namespace std;

class AString
{
protected:
    char *_PChar;

public:
    AString();
    AString(const char *);
    AString(const AString &);

    ~AString();

    void Input();

    void Output() const;

    void Copy(const char *);

    void DeleteNElmentsFromPoz(int, int);

    void StringInsertionFromPoz(const AString &, int);

    int Size() const;

    char* Get_PChar() const;

    friend AString substringNFromPoz(const AString &, int, int);

    friend int firstEnterSubstringInString(const AString &, const AString &);

    friend bool stringIsInt(const AString &);

    friend int stringToInt(const AString &);

    AString &operator=(const AString &);

    AString operator*(const AString &) const;

    AString operator+(const AString &) const;

    bool operator==(const AString &) const;

    friend bool operator!=(const AString &, const AString &);

    bool operator<=(const AString &) const;

    friend bool operator>(const AString &, const AString &);

    bool operator>=(const AString &) const;

    friend bool operator<(const AString &, const AString &);
};
