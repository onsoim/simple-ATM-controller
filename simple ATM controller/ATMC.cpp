//
//  ATMC.cpp
//  simple ATM controller
//
//  Created by onsoim on 2023/05/31.
//

#include <iostream>
#include <vector>
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
        while (!api.checkPIN(cardInfo, PIN)) {
            cout << "[*] Enter your PIN\n> ";
            cin >> PIN;
        }

        int idx = -1;
        int cnt = 1;
        cout << "[*] Select your account\n";
        vector<ll> accounts = api.getAccounts();
        for (auto account: accounts) {
            cout << cnt << ". " << account << endl;
            cnt += 1;
        }
        cout << "> ";
        cin >> idx;
        
        cout << "[*] Select " << accounts[idx - 1] << endl << endl;
        api.setAccount(accounts[idx - 1]);
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
