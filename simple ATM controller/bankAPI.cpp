//
//  bankAPI.cpp
//  simple ATM controller
//
//  Created by onsoim on 2023/05/31.
//

#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

struct USER {
    ll cardInfo;
    int PIN;
    vector<ll> accountNumbers;
};

struct ACCOUNT {
    ll number;
    ll balance;
};

// Core banking systems (bankAPI)
class bankAPI {
private:
    vector<USER> users {
        {1, 1111, {11111111, 11112222}},
        {2, 2222, {22221111, 22222222}},
        {3, 3333, {33331111, 33332222}},
        {4, 4444, {44441111, 44442222}},
        {5, 5555, {55551111, 55552222}},
    };
    vector<ACCOUNT> accounts {
        {11111111, 0},
        {11112222, 0},
        {22221111, 0},
        {22222222, 0},
        {33331111, 0},
        {33332222, 0},
        {44441111, 1000},
        {44442222, 20000},
        {55551111, 300000},
        {55552222, 4999990},
    };
    vector<ll> accountNumbers;
    ACCOUNT account {-1, -1};

public:
    bool checkPIN(ll cardInfo, int PIN) {
        for (auto user: users) {
            if (user.cardInfo == cardInfo && user.PIN == PIN) {
                accountNumbers = user.accountNumbers;
                return true;
            }
        }

        return false;
    }

    vector<ll> getAccounts() { return accountNumbers; }

    bool setAccount(ll accountNumber) {
        for (auto acc: accounts) {
            if (acc.number == accountNumber) {
                account = acc;
                return true;
            }
        }
        return false;
    }

    ll getBalance() { return account.balance; }

    bool setBalance(ll delta) {
        if (getBalance() + delta > -1) {
            account.balance += delta;
            return true;
        }
        return false;
    }
};
