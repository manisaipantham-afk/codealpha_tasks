#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Transaction Class
class Transaction
{
public:
    string type;
    double amount;

    Transaction(string t, double a)
    {
        type = t;
        amount = a;
    }
};

// Customer Class
class Customer
{
public:
    int customerID;
    string customerName;

    Customer(int id, string name)
    {
        customerID = id;
        customerName = name;
    }
};

// Account Class
class Account
{
public:
    int accountNumber;
    double balance;
    Customer customer;
    vector<Transaction> history;

    Account(int accNo, double bal, Customer cust)
        : customer(cust)
    {
        accountNumber = accNo;
        balance = bal;
    }

    void deposit(double amount)
    {
        balance += amount;
        history.push_back(Transaction("Deposit", amount));

        cout << "Deposit Successful!\n";
    }

    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            history.push_back(Transaction("Withdraw", amount));

            cout << "Withdrawal Successful!\n";
        }
        else
        {
            cout << "Insufficient Balance!\n";
        }
    }

    void transfer(Account &receiver, double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            receiver.balance += amount;

            history.push_back(Transaction("Transfer Sent", amount));
            receiver.history.push_back(Transaction("Transfer Received", amount));

            cout << "Transfer Successful!\n";
        }
        else
        {
            cout << "Insufficient Balance!\n";
        }
    }

    void showDetails()
    {
        cout << "\n----- Account Details -----\n";
        cout << "Customer ID : " << customer.customerID << endl;
        cout << "Customer Name : " << customer.customerName << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Balance : " << balance << endl;

        cout << "\nTransaction History:\n";

        if (history.empty())
        {
            cout << "No Transactions Found\n";
        }
        else
        {
            for (int i = 0; i < history.size(); i++)
            {
                cout << history[i].type
                     << " : "
                     << history[i].amount
                     << endl;
            }
        }
    }
};

int main()
{
    // Create Customers
    Customer c1(101, "Ali");
    Customer c2(102, "Ahmed");

    // Create Accounts
    Account acc1(1001, 5000, c1);
    Account acc2(1002, 3000, c2);

    int choice;
    double amount;

    do
    {
        cout << "\n===== BANKING SYSTEM =====\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Transfer\n";
        cout << "4. View Account 1 Details\n";
        cout << "5. View Account 2 Details\n";
        cout << "0. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Deposit Amount: ";
            cin >> amount;
            acc1.deposit(amount);
            break;

        case 2:
            cout << "Enter Withdrawal Amount: ";
            cin >> amount;
            acc1.withdraw(amount);
            break;

        case 3:
            cout << "Enter Transfer Amount: ";
            cin >> amount;
            acc1.transfer(acc2, amount);
            break;

        case 4:
            acc1.showDetails();
            break;

        case 5:
            acc2.showDetails();
            break;

        case 0:
            cout << "Program Ended.\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 0);

    return 0;
}