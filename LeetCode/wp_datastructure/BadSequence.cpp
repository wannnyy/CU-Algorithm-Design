#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int balance = 0, min_balance = 0;
    
    // Calculate balance and track the minimum balance reached
    for (char c : s) {
        balance += (c == '(') ? 1 : -1;
        min_balance = min(min_balance, balance);
    }

    // For a fixable sequence, the total balance must be zero
    // and the minimum balance should not be less than -1
    if (balance == 0 && min_balance >= -1) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}