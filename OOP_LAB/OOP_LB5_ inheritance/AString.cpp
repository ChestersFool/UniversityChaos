#pragma once
#include "AString.h"
#include <iostream>

using namespace std;

AString::AString()
{
    cout << "Builder(ASTRING) -" << this << "\n";
    this->_PChar = nullptr;
}

AString::AString(const char *pCharOuther)
{
    cout << "Builder(ASTRING) -" << this << "\n";

    int sizePCharOuther = 0;
    while (pCharOuther[sizePCharOuther] != '\0')
        sizePCharOuther++;

    this->_PChar = new char[sizePCharOuther + 1];

    int j = 0;
    for (; j < sizePCharOuther; j++)
        this->_PChar[j] = pCharOuther[j];

    this->_PChar[j] = '\0';
}

AString::AString(const AString &OutherString)
{
    cout << "Builder(ASTRING) -" << this << "\n";

    int sizeOutherString = OutherString.Size();

    this->_PChar = new char[sizeOutherString + 1];

    int j = 0;
    for (; j < sizeOutherString; j++)
        this->_PChar[j] = OutherString._PChar[j];

    this->_PChar[j] = '\0';
}

AString::~AString()
{
    cout << "Destruct(ASTRING) -" << this << "\n";
    delete[] this->_PChar;
}

void AString::Input()
{
    char buffer[101];

    cout << "Enter string (to 100 symbols): ";
    cin >> buffer;

    this->Copy(buffer);
}

void AString::Output() const
{
    int i = 0;
    while (this->_PChar[i] != '\0')
        cout << this->_PChar[i++];
}

void AString::Copy(const char *pCharOuther)
{
    int sizePCharOuther = 0;
    while (pCharOuther[sizePCharOuther] != '\0')
        sizePCharOuther++;

    if (this->_PChar != nullptr)
        delete[] this->_PChar;
    this->_PChar = new char[sizePCharOuther + 1];

    int j = 0;
    for (; j < sizePCharOuther; j++)
        this->_PChar[j] = pCharOuther[j];

    this->_PChar[j] = '\0';
}

void AString::DeleteNElmentsFromPoz(int n, int poz)
{
    n -= 1;
    int i = 0, j = 0;

    char *temp = new char[Size()];

    j = i = 0;
    while (this->_PChar[i] != '\0')
    {
        if (!(i >= poz && i <= poz + n))
            temp[j++] = _PChar[i];
        i++;
    }
    temp[j] = '\0';

    this->Copy(temp);
}

void AString::StringInsertionFromPoz(const AString &OutherString, int poz)
{
    int i = this->Size();
    int j = OutherString.Size();

    char *temp = new char[i + j + 1];

    int t = 0;

    if (i < poz)
        return;

    i = 0;
    while (i < poz)
        temp[t++] = this->_PChar[i++];

    j = 0;
    while (OutherString._PChar[j] != '\0')
        temp[t++] = OutherString._PChar[j++];

    while (this->_PChar[i] != '\0')
        temp[t++] = this->_PChar[i++];

    temp[t] = '\0';

    this->Copy(temp);
}

int AString::Size() const
{
    int i = 0;
    while (this->_PChar[i] != '\0')
        i++;

    return i;
}

char* AString::Get_PChar() const
{
    return this->_PChar;
}

AString substringNFromPoz(const AString &OutherString, int n, int poz)
{
    char *temp = new char[n-- + 1];

    int i = 0, j = 0;
    while (OutherString._PChar[i] != '\0')
    {
        if ((i >= poz && i <= poz + n))
            temp[j++] = OutherString._PChar[i];
        i++;
    }
    temp[j] = '\0';

    AString Temp(temp);

    return Temp;
}

int firstEnterSubstringInString(const AString &String, const AString &SubString)
{
    if (String._PChar == nullptr || SubString._PChar == nullptr)
        return -1;

    int sizeStr = String.Size();
    int sizeSubstr = SubString.Size();

    if (sizeSubstr > sizeStr)
        return -1;

    for (int i = 0, j; i <= sizeStr - sizeSubstr; i++)
    {
        j = 0;
        for (; j < sizeSubstr; j++)
            if (String._PChar[i + j] != SubString._PChar[j])
                break;

        if (j == sizeSubstr)
            return i;
    }

    return -1;
}

// 1 - 48 // 9 - 57
bool stringIsInt(const AString &String)
{
    if (String._PChar == nullptr)
        return false;

    int sizeStr = String.Size(), temp;
    for (int i = 0; i < sizeStr; i++)
    {
        temp = String._PChar[i];
        if (temp < 48 || temp > 57)
            return false;
    }

    return true;
}

int stringToInt(const AString &String)
{
    if (stringIsInt(String))
    {
        int temp = atoi(String._PChar);
        return temp;
    }

    return 0;
}

AString &AString::operator=(const AString &OutherString)
{
    if (this == &OutherString)
        return *this;

    delete[] this->_PChar;

    int sizeOutherString = OutherString.Size();
    this->_PChar = new char[sizeOutherString + 1];

    int j = 0;
    for (; j < sizeOutherString; j++)
        this->_PChar[j] = OutherString._PChar[j];

    this->_PChar[j] = '\0';

    return *this;
}

AString AString::operator*(const AString &OutherString) const
{
    int sizeOutherString = OutherString.Size();
    char *temp = new char[sizeOutherString + 1];

    bool alreadyThere = false;
    int i = 0, t = 0;
    while (this->_PChar[i] != '\0')
    {
        alreadyThere = false;
        for (int j = 0; j < sizeOutherString; j++)
        {
            if (this->_PChar[i] == OutherString._PChar[j])
            {
                alreadyThere = true;
                break;
            }
        }

        if (alreadyThere)
        {
            for (int k = 0; k < t; k++)
                if (this->_PChar[i] == temp[k])
                {
                    alreadyThere = false;
                    break;
                }

            if (alreadyThere)
                temp[t++] = this->_PChar[i];
        }
        i++;
    }
    temp[t] = '\0';

    AString Temp(temp);
    return Temp;
}

AString AString::operator+(const AString &OutherString) const
{
    int sizeThis = this->Size();
    int sizeOutherString = OutherString.Size();
    char *temp = new char[sizeOutherString + sizeThis + 1];

    int i = 0;
    while (this->_PChar[i] != '\0')
        temp[i++] = this->_PChar[i];

    int j = 0;
    while (OutherString._PChar[j] != '\0')
        temp[i++] = OutherString._PChar[j++];

    temp[i] = '\0';

    AString Temp(temp);
    return Temp;
}

bool AString::operator==(const AString &OutherString) const
{
    int sizeThis = Size();
    int sizeOutherString = OutherString.Size();

    if (sizeThis != sizeOutherString)
        return false;

    for (int i = 0; i < sizeThis; i++)
        if (this->_PChar[i] != OutherString._PChar[i])
            return false;

    return true;
}

bool operator!=(const AString &FirstOutherString, const AString &SecondOutherString)
{
    return !(FirstOutherString == SecondOutherString);
}

bool AString::operator<=(const AString &OutherString) const
{
    int sizeThis = Size();
    int sizeOutherString = OutherString.Size();

    if (sizeThis < sizeOutherString)
        return true;
    if (sizeThis > sizeOutherString)
        return false;

    int sumThis = 0, sumOuther = 0;
    for (int i = 0; i < sizeThis; i++)
        sumThis += this->_PChar[i++];

    for (int i = 0; i < sizeThis; i++)
        sumOuther += OutherString._PChar[i++];

    if (sumThis <= sumOuther)
        return true;
    return false;
}

bool operator>(const AString &FirstOutherString, const AString &SecondOutherString)
{
    return !(FirstOutherString <= SecondOutherString);
}

bool AString::operator>=(const AString &OutherString) const
{
    int sizeThis = Size();
    int sizeOutherString = OutherString.Size();

    if (sizeThis < sizeOutherString)
        return false;
    if (sizeThis > sizeOutherString)
        return true;

    int sumThis = 0, sumOuther = 0;
    for (int i = 0; i < sizeThis; i++)
        sumThis += this->_PChar[i++];

    for (int i = 0; i < sizeThis; i++)
        sumOuther += OutherString._PChar[i++];

    if (sumThis >= sumOuther)
        return true;
    return false;
}

bool operator<(const AString &FirstOutherString, const AString &SecondOutherString)
{
    return !(FirstOutherString >= SecondOutherString);
}