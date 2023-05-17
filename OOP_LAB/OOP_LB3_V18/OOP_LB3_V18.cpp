#include <iostream>
#include <cstring>

using namespace std;

struct TBankomat
{
    int id, min_withdraw, max_withdraw;
    int current_amount[9];
};

void init_atm(TBankomat &, int = 0, int[] = nullptr, int = 0, int = 0);

void input_atm(TBankomat &);

void output_atm(TBankomat);

void deposit_money_atm(TBankomat &, int[]);

void atm_withdrawal(TBankomat &, int &);

char *toPChar_atm(TBankomat);

char *toString(TBankomat);

int main()
{
    TBankomat first;
    char *info;
    cout << "init_atm was called!\n";
    init_atm(first);

    int temp[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    cout << "init_atm was called!\n";
    init_atm(first, 2, temp, 4, 5000);
    cout << "output_atm was called!\n";
    output_atm(first);

    cout << "\ninput_atm was called\n";
    input_atm(first);   
    cout << "output_atm was called!\n";
    output_atm(first);

    for (int i = 0; i < 9; i++)
        temp[i] = 0;
    cout << "\ndeposit_money_atm was called!";
    deposit_money_atm(first, temp);
    cout << "\ntoString was called!\n";
    info = toString(first);
    cout << info;
    delete[] info;

    int amount = 604; // сума грошей яку ми хочемо отримати
    cout << "\natm_withdrawal was called!\n";
    atm_withdrawal(first, amount);
    cout << "AMOUNT - " << amount;
    cout << "\ntoString was called!\n";
    info = toString(first);
    cout << info;
    delete[] info;

    cout << "\ntoPchar_atm was called!\n";
    info = toPChar_atm(first);
    cout << info;
    delete[] info;

    return 0;
}

void init_atm(TBankomat &atm, int id, int current_amount[], int min_withdraw, int max_withdraw)
{
    atm.id = id;
    if (current_amount != nullptr)
        for (int i = 0; i < 9; i++)
            atm.current_amount[i] = current_amount[i];
    atm.min_withdraw = min_withdraw;
    atm.max_withdraw = max_withdraw;
}

void input_atm(TBankomat &atm)
{
    cout << "Enter current amount of money in this ATM (1 2 5 10 20 50 100 200 500): ";
    for (int i = 0; i < 9; i++)
        cin >> atm.current_amount[i];
    cout << "Enter min withdraw money in this ATM: ";
    cin >> atm.min_withdraw;
    cout << "Enter max withdraw money in this ATM: ";
    cin >> atm.max_withdraw;
}

void output_atm(TBankomat atm)
{
    cout << "ATM id - " << atm.id << "\nATM min withdraw: " << atm.min_withdraw << "\nATM max withdraw: " << atm.max_withdraw;
    cout << "\nATM current amount of money (1 2 5 10 20 50 100 200 500): ";
    for (int i = 0; i < 9; i++)
        cout << atm.current_amount[i] << " ";
}

void deposit_money_atm(TBankomat &atm, int amount_of_money[9])
{
    for (int i = 0; i < 9; i++)
        atm.current_amount[i] += amount_of_money[i];
}

void atm_withdrawal(TBankomat &atm, int &amount)
{
    if (amount > atm.max_withdraw || amount < atm.min_withdraw)
        return;

    while (amount / 500.0 >= 1 && atm.current_amount[8] > 0)
    {
        amount -= 500;
        atm.current_amount[8] -= 1;
    }
    while (amount / 200.0 >= 1 && atm.current_amount[7] > 0)
    {
        amount -= 200;
        atm.current_amount[7] -= 1;
    }
    while (amount / 100.0 >= 1 && atm.current_amount[6] > 0)
    {
        amount -= 100;
        atm.current_amount[6] -= 1;
    }
    while (amount / 50.0 >= 1 && atm.current_amount[5] > 0)
    {
        amount -= 50;
        atm.current_amount[5] -= 1;
    }
    while (amount / 20.0 >= 1 && atm.current_amount[4] > 0)
    {
        amount -= 20;
        atm.current_amount[4] -= 1;
    }
    while (amount / 10.0 >= 1 && atm.current_amount[3] > 0)
    {
        amount -= 10;
        atm.current_amount[3] -= 1;
    }
    while (amount / 5.0 >= 1 && atm.current_amount[2] > 0)
    {
        amount -= 5;
        atm.current_amount[2] -= 1;
    }
    while (amount / 2.0 >= 1 && atm.current_amount[1] > 0)
    {
        amount -= 2;
        atm.current_amount[1] -= 1;
    }
    while (amount / 1.0 >= 1 && atm.current_amount[0] > 0)
    {
        amount -= 1;
        atm.current_amount[0] -= 1;
    }
}

char *toPChar_atm(TBankomat atm)
{
    char *info = new char[100];
    char *temp = new char[10];
    sprintf(info, "ATM id - %d; ATM min withdraw - %d; ATM max withdraw - %d; ATM current amount of money (1 2 5 10 20 50 100 200 500) -", atm.id, atm.min_withdraw, atm.max_withdraw);
    for (int i = 0; i < 9; i++)
    {
        sprintf(temp, " %d", atm.current_amount[i]);
        strcat(info, temp);
    }
    return info;
}

char *toString(TBankomat atm)
{
    char *info = new char[200];
    char *temp = new char[10];
    sprintf(info, "ATM current amount of money (1 2 5 10 20 50 100 200 500) -");
    for (int i = 0; i < 9; i++)
    {
        sprintf(temp, " %d", atm.current_amount[i]);
        strcat(info, temp);
    }
    return info;
}
