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
    struct USER {
        ll cardInfo = 12341234;
        int PIN = 1234;
        ll accounNumber = 123412341234;
    } user;

    struct ACCOUNT {
        ll accounNumber = 123412341234;
        ll balance = 0;
    } account;

public:
    bool checkPIN(int PIN) {
        return user.PIN == PIN;
    }

    ll getBalance() {
        return account.balance;
    }

    bool setBalance(ll delta) {
        account.balance += delta;
        return true;
    }
};

// A system between ATMs (client) and core banking systems (bankAPI)
class ATMC {
private:
    bankAPI api;
    ll accountNumber = NULL;

    ll cashBin = 0;
public:
    void setAccount() {
        cout << "[*] Set account number\n";

        ll cardInfo = NULL;
        cout << "[*] Insert your card\n> ";
        cin >> cardInfo;

        int PIN = 0;
        while (!api.checkPIN(PIN)) {
            cout << "[*] Enter your PIN\n> ";
            cin >> PIN;
        }

        cout << "[*] Select your account\n> ";
        cin >> accountNumber;
    }

    ll getBalance() {
        if (!accountNumber) setAccount();
        return api.getBalance();
    }

    bool setBalance(ll delta) {
        if (!accountNumber) setAccount();

        if (delta >= 0 ||  cashBin + delta >= 0) {
            bool res = api.setBalance(delta);
            if (res) cashBin += delta;
            return res;
        }
        return false;
    }
};

// An ATM (client)
class CLIENT {
private:
    ATMC controller;
public:
    ll getBalance(bool menu = false) {
        ll balance = controller.getBalance();

        if (menu) {
            cout << "[$] Balance is: $" << balance << endl << endl;
        }

        return balance;
    }

    bool setBalance(ll amount) {
        if (getBalance() + amount > -1) {
            return controller.setBalance(amount);
        }
        return false;
    }

    bool deposit() {
        ll amount = 0;

        cout << "[$] Enter amount to be Deposited\n$";
        cin >> amount;

        return setBalance(amount);
    }

    bool deposit(ll amount) {
        return setBalance(amount);
    }

    bool withdraw(ll amount = 0) {
        ll value = 0;

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
                    cout << "[!] Can't withdraw money!" << endl << endl;
                }
                break;
            case 4: return 0;
            default:
                cout << "[!] Invalid options.\n[!] Try again with valid options.\n";
        }
    }
}