#include <iostream>
using namespace std;

void deposit(int &balance, const int &amount);
bool withdraw(int &balance, const int &amount);
void processTransaction(int &balance);

int main()
{
    int balance, transactions;

    cout << "Enter the initial account balance: ";
    cin >> balance;

    cout << "Enter the number of transactions: ";
    cin >> transactions;

    for (int i = 0; i < transactions; i++)
    {
        processTransaction(balance);
    }

    cout << "\nFinal balance: " << balance << endl;
    return 0;
}

void deposit(int &balance, const int &amount)
{
    balance = balance + amount;
}

bool withdraw(int &balance, const int &amount)
{
    if (balance >= amount) 
    {
        balance -= amount;
        return true;
    }
    return false;
}

void processTransaction(int &balance)
{
    char select;
    int amount;

    cout << "Enter D or W: ";
    cin >> select;

    if (select == 'W')  
    {
        cin >> amount;
        if(withdraw(balance, amount)==0)
        {
            cout<<"invalid withdraw\n";
        }
    }
    else if (select == 'D')
    {
        cin >> amount;
        deposit(balance, amount);
    }
    else
    {
        cout << "invalid transaction\n";
    }
}

