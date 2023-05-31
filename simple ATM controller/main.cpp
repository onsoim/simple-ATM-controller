//
//  main.cpp
//  simple ATM controller
//
//  Created by onsoim on 2023/05/31.
//

#include <iostream>

using namespace std;

class ATMC {
private:
    string account;
public:
    void insertCard() {}
    void checkPIN() {}
    void setAccount() {}
    void getBalance() {}
    void deposit() {}
    void withdraw() {}
};

int main(int argc, const char * argv[]) {
    int menu = -1;

    while (1) {
        cout << "1. Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Quit\n";
        cout << "> ";

        cin >> menu;
        switch (menu) {
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: return 0;
            default:
                cout << "[!] Invalid options.\n[!] Try again with valid options.\n";
        }
    }
}
