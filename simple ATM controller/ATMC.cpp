//
//  ATMC.cpp
//  simple ATM controller
//
//  Created by onsoim on 2023/05/31.
//

#include <iostream>
#include "bankAPI.cpp"

typedef long long ll;

using namespace std;

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
