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
    ll getAccount() { return accountNumber; }

    void setAccount() {
        cout << "[*] Set account number\n";

    RESET:
        ll cardInfo = NULL;
        cout << "[*] Insert your card\n> ";
        cin >> cardInfo;

        int PIN = 0;
        while (!api.checkPIN(cardInfo, PIN)) {
            cout << "[*] Enter your PIN (-1 will reset cardInfo)\n> ";
            cin >> PIN;

            if (PIN == -1) goto RESET;
        }

        int idx = -1;
        vector<ll> accounts = api.getAccounts();

        while (idx <= 0 || idx > accounts.size()) {
            cout << "[*] Select your account (-1 will reset cardInfo)\n";
            int cnt = 1;
            for (auto account: accounts) {
                cout << cnt << ". " << account << endl;
                cnt += 1;
            }
            cout << "> ";
            cin >> idx;
            if (idx == -1) goto RESET;
        }

        cout << "[*] Select " << accounts[idx - 1] << endl << endl;
        api.setAccount(accounts[idx - 1]);
        accountNumber = accounts[idx - 1];
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
