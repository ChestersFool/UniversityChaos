#include <iostream>
#include <cstring>

using namespace std;

class Tbankomat
{
private:
    struct atm
    {
    public:
        int id, min_withdraw, max_withdraw;
        int current_amount[9];
    };
    atm first;

public:
    void init(int = 0, int[] = nullptr, int = 0, int = 0);
    void input();
    void output();
    char *toPChar();

    void set_id(int);
    void set_min_withdraw(int);
    void set_max_withdraw(int);
    void set_current_amount(int[9]);

    int *get_current_amount();
    int get_min_withdraw();
    int get_max_withdraw();
};

void Tbankomat::init(int id, int current_amount[], int min_withdraw, int max_withdraw)
{
    first.id = id;
    if (current_amount != nullptr)
        for (int i = 0; i < 9; i++)
            first.current_amount[i] = current_amount[i];
    first.min_withdraw = min_withdraw;
    first.max_withdraw = max_withdraw;
}

void Tbankomat::input()
{
    cout << "Enter current amount of money in this ATM (1 2 5 10 20 50 100 200 500): ";
    for (int i = 0; i < 9; i++)
        cin >> first.current_amount[i];
    cout << "Enter min withdraw money in this ATM: ";
    cin >> first.min_withdraw;
    cout << "Enter max withdraw money in this ATM: ";
    cin >> first.max_withdraw;
}

void Tbankomat::output()
{
    cout << "ATM id - " << first.id << "\nATM min withdraw: " << first.min_withdraw << "\nATM max withdraw: " << first.max_withdraw;
    cout << "\nATM current amount of money (1 2 5 10 20 50 100 200 500): ";
    for (int i = 0; i < 9; i++)
        cout << first.current_amount[i] << " ";
}

char *Tbankomat::toPChar()
{
    char *info = new char[100];
    char *temp = new char[10];
    sprintf(info, "ATM id - %d; ATM min withdraw - %d; ATM max withdraw - %d; ATM current amount of money (1 2 5 10 20 50 100 200 500) -", first.id, first.min_withdraw, first.max_withdraw);
    for (int i = 0; i < 9; i++)
    {
        sprintf(temp, " %d", first.current_amount[i]);
        strcat(info, temp);
    }
    return info;
}

void Tbankomat::set_id(int id)
{
    first.id = id;
}

void Tbankomat::set_min_withdraw(int min_withdraw)
{
    first.min_withdraw = min_withdraw;
}

void Tbankomat::set_max_withdraw(int max_withdraw)
{
    first.max_withdraw = max_withdraw;
}

void Tbankomat::set_current_amount(int current_amount[9])
{
    for (int i = 0; i < 9; i++)
        first.current_amount[i] = current_amount[i];
}

int *Tbankomat::get_current_amount()
{
    int *temp = new int[9];
    for (int i = 0; i < 9; i++)
        temp[i] = first.current_amount[i];

    return temp;
}

int Tbankomat::get_min_withdraw()
{
    return first.min_withdraw;
}

int Tbankomat::get_max_withdraw()
{
    return first.max_withdraw;
}

void deposit_money_atm(Tbankomat &, int[]);

void atm_withdrawal(Tbankomat &, int &);

char *toString(Tbankomat);

int main()
{
    Tbankomat a;
    char *info;
    cout << "init was called!\n";
    a.init();

    int temp[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    cout << "init was called!\n";
    a.init(1, temp, 10, 100000);
    cout << "output was called!\n";
    a.output();

    cout << "\ninput was called!\n";
    a.input();
    cout << "output was called!\n";
    a.output();

    int t[9] = {2, 2, 2, 2, 2, 2, 2, 2, 2};
    cout << "\nSetters was called\n";
    a.set_id(2);
    a.set_max_withdraw(10002);
    a.set_min_withdraw(1);
    a.set_current_amount(t);
    cout << "output was called!\n";
    a.output();

    cout << "\ndeposit_money_atm was called!\n";
    deposit_money_atm(a, t);
    cout << "toString was called!\n";
    info = toString(a);
    cout << info;
    delete[] info;

    int amount = 1463;
    cout << "\natm_withdrawal was called!\n";
    atm_withdrawal(a, amount);
    cout << "AMOUNT - " << amount;
    cout << "\ntoString was called!\n";
    info = toString(a);
    cout << info;
    delete[] info;

    cout << "\ntoPchar was called!\n";
    info = a.toPChar();
    cout << info;
    delete[] info;

    return 0;
}

void deposit_money_atm(Tbankomat &a, int current_amount[9])
{
    int *temp = a.get_current_amount();
    for (int i = 0; i < 9; i++)
        temp[i] += current_amount[i];

    a.set_current_amount(temp);
}

void atm_withdrawal(Tbankomat &a, int &amount)
{
    int *temp = a.get_current_amount();
    int min_withdraw = a.get_min_withdraw(), max_withdraw = a.get_max_withdraw();

    if (amount > max_withdraw || amount < min_withdraw)
        return;

    while (amount / 500.0 >= 1 && temp[8] > 0)
    {
        amount -= 500;
        temp[8] -= 1;
    }
    while (amount / 200.0 >= 1 && temp[7] > 0)
    {
        amount -= 200;
        temp[7] -= 1;
    }
    while (amount / 100.0 >= 1 && temp[6] > 0)
    {
        amount -= 100;
        temp[6] -= 1;
    }
    while (amount / 50.0 >= 1 && temp[5] > 0)
    {
        amount -= 50;
        temp[5] -= 1;
    }
    while (amount / 20.0 >= 1 && temp[4] > 0)
    {
        amount -= 20;
        temp[4] -= 1;
    }
    while (amount / 10.0 >= 1 && temp[3] > 0)
    {
        amount -= 10;
        temp[3] -= 1;
    }
    while (amount / 5.0 >= 1 && temp[2] > 0)
    {
        amount -= 5;
        temp[2] -= 1;
    }
    while (amount / 2.0 >= 1 && temp[1] > 0)
    {
        amount -= 2;
        temp[1] -= 1;
    }
    while (amount / 1.0 >= 1 && temp[0] > 0)
    {
        amount -= 1;
        temp[0] -= 1;
    }
    a.set_current_amount(temp);
}

char *toString(Tbankomat a)
{
    char *info = new char[100];
    char *temp = new char[10];
    int *current_amount = a.get_current_amount();
    sprintf(info, "ATM current amount of money (1 2 5 10 20 50 100 200 500) -");
    for (int i = 0; i < 9; i++)
    {
        sprintf(temp, " %d", current_amount[i]);
        strcat(info, temp);
    }
    return info;
}