//
//  bankAPI.cpp
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
