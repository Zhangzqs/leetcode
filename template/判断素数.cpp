#include <bits/stdc++.h>

using namespace std;

bool isPrime1(int n) {
    if (n < 2) return false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool isPrime2(int n) {
    if (n < 2) return false;
    int sn = sqrt(n);
    for (int i = 2; i <= sn; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool isPrime3(int n) {
    if (n < 2) return false;
    int sn = sqrt(n);
    for (int i = 2; i <= sn; i++) {
        if (n % 2 == 0 || n % i == 0) return false;
    }
    return true;
}

int main() {
    for (int i = 0; i < 100; i++) {
        cout << i << endl;
        assert(isPrime1(i) == isPrime2(i));
        assert(isPrime2(i) == isPrime3(i));
    }
    return 0;
}