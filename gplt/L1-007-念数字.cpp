#include <bits/stdc++.h>

using namespace std;

int main() {
    string ss[] = {"ling", "yi",  "er", "san", "si",
                   "wu",   "liu", "qi", "ba",  "jiu"};
    long long num;
    cin >> num;
    if(num == 0) cout<< "ling";
    if (num < 0) cout << "fu ";
    long long posNum = abs(num);
    int st[100];
    int top = 0;
    while (posNum != 0) {
        int n = posNum % 10;
        posNum /= 10;
        st[top++] = n;
    }
    while (top > 0) {
        int n = st[--top];
        cout << ss[n];
        if (top != 0) cout << " ";
    }
    return 0;
}