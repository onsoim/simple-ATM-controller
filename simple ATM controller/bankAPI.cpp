//
//  bankAPI.cpp
//  simple ATM controller
//
//  Created by onsoim on 2023/05/31.
//

#include <iostream>
#include <list>

typedef long long ll;

using namespace std;

struct USER {
    ll cardInfo;
    int PIN;
    list<ll> accountNumbers;
};

struct ACCOUNT {
    ll accounNumber;
    ll balance;
};

// Core banking systems (bankAPI)
class bankAPI {
private:
    USER user {12341234, 1234, {123412341234, 1413414214}};
    ACCOUNT account {123412341234, 0};

public:
    bool checkPIN(int PIN) {
        return user.PIN == PIN;
    }

    ll getBalance() {
        return account.balance;
    }

    bool setBalance(ll delta) {
        if (getBalance() + delta > -1) {
            account.balance += delta;
            return true;
        }
        return false;
    }
};
