//
//  main.cpp
//  simple ATM controller
//
//  Created by onsoim on 2023/05/31.
//

#include <iostream>

typedef long long ll;

using namespace std;

// Core banking systems (bankAPI)
class bankAPI {
private:
    ll balance = 0;
public:
    bool checkPIN(int PIN) {
        return PIN == 1234;
    }

    ll getBalance() {
        return balance;
    }

    bool setBalance(ll delta) {
        balance += delta;
        return true;
    }
};

// A system between ATMs (client) and core banking systems (bankAPI)
class ATMC {
private:
   int cashBin = 0;
   bankAPI api;
public:
    void checkPIN() {}
    void setAccount() {}

    ll getBalance() {
        return api.getBalance();
    }

    bool setBalance(ll delta) {
        return api.setBalance(delta);
    }
};

// An ATM (client)
class CLIENT {
private:
    struct ACCOUNT {
        string number = "";
        int balance = 0;
    } account;
    ATMC atmc;
public:
    void insertCard() {}

    int getBalance(bool menu = false) {
        ll balance = atmc.getBalance();

        if (menu) {
            cout << "[$] Balance is: $" << balance << endl << endl;
        }

        return balance;
    }

    bool setBalance(int amount) {
        int transaction = getBalance() + amount;

        if (transaction > -1) {
            return atmc.setBalance(amount);
        }
        return false;
    }

    bool deposit() {
        int amount = 0;

        cout << "[$] Enter amount to be Deposited\n$";
        cin >> amount;

        return setBalance(amount);
    }

    bool deposit(int amount) {
        return setBalance(amount);
    }

    bool withdraw(int amount = 0) {
        int value = 0;

        if (amount == 0) {
            cout << "[$] Enter amount to withdraw\n$";
            cin >> value;
        }
        else value = amount;

        return setBalance(-value);
    }
};

int main(int argc, const char * argv[]) {
    CLIENT client;

    int menu = -1;

    while (1) {
        cout << "[*] Menu\n";
        cout << "1. Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Quit\n";
        cout << "> ";

        cin >> menu;
        switch (menu) {
            case 1:
                client.getBalance(true);
                break;
            case 2:
                if (client.deposit()) {
                    client.getBalance(true);
                }
                break;
            case 3:
                if (client.withdraw()) {
                    client.getBalance(true);
                }
                else {
                    cout << "[!] Can't withdraw money!"<< endl << endl;
                }
                break;
            case 4: return 0;
            default:
                cout << "[!] Invalid options.\n[!] Try again with valid options.\n";
        }
    }
}
