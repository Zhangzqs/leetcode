#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> tab(10);
    for (char& ch : s) tab[ch - '0']++;
    for (int i = 0; i < 10; i++) {
        if (tab[i] == 0) continue;
        cout << i << ":" << tab[i] << endl;
    }
    return 0;
}