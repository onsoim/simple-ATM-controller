//
//  main.cpp
//  simple ATM controller
//
//  Created by onsoim on 2023/05/31.
//

#include <iostream>

using namespace std;

//class ATMC {
//private:
//    int cashBin = 0;
//
//};

class CLIENT {
private:
    struct ACCOUNT {
        string number = "";
        int balance = 0;
    } account;
public:
    void insertCard() {}
    void checkPIN() {}
    void setAccount() {}

    int getBalance(bool menu = false) {
        if (menu) {
            cout << "[$] Balance is: $" << account.balance << endl << endl;
        }
        return account.balance;
    }

    bool setBalance(int amount) {
        int transaction = getBalance() + amount;

        if (transaction > -1) {
            account.balance = getBalance() + amount;
            return true;
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
