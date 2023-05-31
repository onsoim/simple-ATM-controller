//
//  main.cpp
//  simple ATM controller
//
//  Created by onsoim on 2023/05/31.
//

#include <iostream>
#include "ATM.cpp"

typedef long long ll;

using namespace std;

int main(int argc, const char * argv[]) {
    ATM atm;
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
                atm.getBalance(true);
                break;
            case 2:
                if (atm.deposit()) {
                    atm.getBalance(true);
                }
                break;
            case 3:
                if (atm.withdraw()) {
                    atm.getBalance(true);
                }
                else {
                    cout << "[!] Can't withdraw money!" << endl << endl;
                }
                break;
            case 4: return 0;
            default:
                cout << "[!] Invalid options.\n[!] Try again with valid options.\n\n";
        }
    }
}
