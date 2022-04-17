#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> zkz(N);
    vector<int> sjzwh(N);
    vector<int> kszwh(N);
    unordered_map<int, int> sjzwhAndIndex;
    for (int i = 0; i < N; i++) {
        cin >> zkz[i] >> sjzwh[i] >> kszwh[i];
        sjzwhAndIndex[sjzwh[i]] = i;
    }
    int M;
    cin >> M;
    vector<int> querySjzwh(M);
    for (int i = 0; i < M; i++) cin >> querySjzwh[i];

    for (int i = 0; i < M; i++) {
        int idx = sjzwhAndIndex[querySjzwh[i]];
        cout << zkz[idx] << " " << kszwh[idx] << endl;
    }

    return 0;
}