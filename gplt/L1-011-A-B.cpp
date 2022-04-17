#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 10000;
    char A[N], B[N];
    bool needFilter[128];
    for (int i = 0; i < 128; i++) needFilter[i] = false;
    cin.getline(A, N);
    cin.getline(B, N);
    char *ch = B;

    while (*ch != '\0') {
        needFilter[*ch] = true;
        ch++;
    }

    ch = A;
    while (*ch != '\0') {
        if (!needFilter[*ch]) printf("%c", *ch);
        ch++;
    }
    return 0;
}