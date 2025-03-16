#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Bankaccount {
protected:
    double balance;
    string ownerName;
    string accountNumber;

public:
    Bankaccount(string ownerName, string accountNumber, double balance) {
        this->ownerName = ownerName;
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    virtual void deposit(double amountDeposit) = 0;
    virtual void withdraw(double amountWithdraw) = 0;

    double getBalance() { return balance; }
    string getAccountNumber() { return accountNumber; }
    string getOwnerName() { return ownerName; }

    friend class BankManagement;
};

class BankAccount : public Bankaccount {
public:
    BankAccount(string ownerName, string accountNumber, double balance)
        : Bankaccount(ownerName, accountNumber, balance) {}

    void deposit(double amountDeposit) override {
        if (amountDeposit >= 0) {
            balance += amountDeposit; // Update the class member directly
            cout << "You deposited " << amountDeposit << " successfully\n";
        } else {
            cout << "Please enter a valid amount to deposit\n";
        }
    }

    void withdraw(double amountWithdraw) override {
        if (amountWithdraw > balance) {
            cout << "Withdrawal failed: Insufficient balance\n";
        } else if (amountWithdraw <= 0) {
            cout << "Please enter an amount greater than 0\n";
        } else {
            balance -= amountWithdraw; // Update the class member directly
            cout << "You successfully withdrew " << amountWithdraw << endl;
        }
    }
};

class BankManagement {
protected:
    vector<BankAccount> accounts;

public:
    void createAccount(const string &ownerName, const string &accountNumber, double balance) {
        if (findAccount(accountNumber)) {
            cout << "Account with number " << accountNumber << " already exists!\n";
            return;
        }
        accounts.emplace_back(ownerName, accountNumber, balance);
        cout << "Account created successfully!\n";
    }

    BankAccount *findAccount(string accountNumber) {
        for (int i = 0; i < accounts.size(); i++) {
            if (accounts[i].getAccountNumber() == accountNumber) {
                return &accounts[i];
            }
        }
        return nullptr;
    };
};

int main() {
    BankManagement bank;
    // Correct order: ownerName, accountNumber, balance
    bank.createAccount("Alice", "1001", 5000);
    bank.createAccount("Bob", "1002", 7000);

    BankAccount *aliceAccount = bank.findAccount("1001");
    if (aliceAccount) {
        cout << "Account found! Owner: " << aliceAccount->getOwnerName()
             << ", Balance: " << aliceAccount->getBalance() << " VND\n";
    } else {
        cout << "Account not found.\n";
    }

    aliceAccount->deposit(2000);

    cout << "Your balance is :" <<   aliceAccount->getBalance() << endl;


    // Find Alice's account
    
    return 0;
}