
// 0 - 3 months:
// Meta (11)

// 6 months ago:
// Google (4) — Uber (3)

// Problem_Link: https://leetcode.ca/all/246.html

#include <iostream>
#include <string>
using namespace std;

bool isStrobogrammatic(string num) {
    int i = 0;
    int j = num.size() - 1;

    while (i <= j) {
        char a = num[i];
        char b = num[j];

        if ((a == '0' && b == '0') ||
            (a == '1' && b == '1') ||
            (a == '8' && b == '8') ||
            (a == '6' && b == '9') ||
            (a == '9' && b == '6')) {
            i++;
            j--;
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    string num;
    cin >> num;

    if (isStrobogrammatic(num)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}