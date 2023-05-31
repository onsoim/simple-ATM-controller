//
//  CLIENT.cpp
//  simple ATM controller
//
//  Created by onsoim on 2023/05/31.
//

#include <iostream>
#include "ATMC.cpp"

typedef long long ll;

using namespace std;

// An ATM (client)
class ATM {
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
        if (!controller.getAccount()) controller.setAccount();

        ll amount = 0;

        cout << "[$] Enter amount to be Deposited\n$";
        cin >> amount;

        return setBalance(amount);
    }

    bool deposit(ll amount) {
        return setBalance(amount);
    }

    bool withdraw(ll amount = 0) {
        if (!controller.getAccount()) controller.setAccount();

        ll value = 0;

        if (amount == 0) {
            cout << "[$] Enter amount to withdraw\n$";
            cin >> value;
        }
        else value = amount;

        return setBalance(-value);
    }
};
