#include <bits/stdc++.h>

using namespace std;

int myPow(int x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    int a = myPow(x, n / 2);
    if (n % 2 == 0) {
        return a * a;
    } else {
        return a * a * x;
    }
}

int main() {
    for (int i = 0; i < 10; i++) {
        cout << i << ": " << myPow(10, i) << endl;
    }
    return 0;
}