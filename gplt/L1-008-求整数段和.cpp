#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    int sum = 0;
    for (int i = A; i <= B; i++) {
        sum += i;
        if (i != A && (i - A) % 5 == 0) cout << endl;
        cout << setw(5) << i;
    }
    cout << endl;
    printf("Sum = %d", sum);
    return 0;
}