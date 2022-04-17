#include <bits/stdc++.h>

using namespace std;

// 数列a(n)表示1,3,5,...,a(n)
int a(int n) { return 2 * n - 1; }

// 有1,3,...,a(n)个*的总最小*数
int S(int n) { return 2 * n * n - 1; }

// 现在必须要能够组成沙漏， 即S(n) <= N
// 解方程得n最大正整数值为T(n)
int T(int N) { return int(sqrt(double((N + 1)) / 2.0)); }

void printLine(char ch, int len, int maxLen) {
    int spLen = (maxLen - len) / 2;
    for (int i = 0; i < spLen; i++) cout << ' ';
    for (int i = 0; i < len; i++) cout << ch;
    cout << endl;
}
void display(char ch, int n) {
    int maxLen = a(n);
    for (int i = n; i >= 1; i--) printLine(ch, a(i), maxLen);
    for (int i = 2; i <= n; i++) printLine(ch, a(i), maxLen);
}

int main() {
    int N;
    char ch;
    cin >> N;
    cin >> ch;

    int n = T(N);
    // cout << "n: " << n << endl;
    display(ch, n);
    int remain = N - S(n);
    cout << remain << endl;
    return 0;
}