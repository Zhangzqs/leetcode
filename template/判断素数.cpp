#include <bits/stdc++.h>

using namespace std;

bool isPrime1(int n) {
    if (n < 2) return false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
int main() {
    for (int i = 0; i < 100; i++) {
        if (isPrime1(i)) {
            cout << i << endl;
        }
    }
    return 0;
}