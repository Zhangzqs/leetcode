#include <bits/stdc++.h>

using namespace std;

const int maxW = 2000;
const int N = 10;
int w[N] = {
    200, 350, 500, 430, 320,  //
    120, 700, 420, 250, 100,
};
int v[N] = {
    15, 45,  100, 70, 50,  //
    75, 200, 90,  20, 30,
};

bool b[N];

// 当前重量
int cw = 0;
// 当前价值
int cv = 0;

// 最优价值
int bestV = 0;
int bestW = 0;
bool bestX[N];
void backtrack(int next) {
    if (next >= N) {
        if (cv >= bestV) {
            bestV = cv;
            bestW = cw;
            memcpy(bestX, b, sizeof(bool) * N);
        }
        return;
    }
    for (int i = 0; i < 2; i++) {
        b[next] = i;
        if (cw + w[next] * i <= maxW) {
            cv += v[next] * i;
            cw += w[next] * i;
            backtrack(next + 1);
            cv -= v[next] * i;
            cw -= w[next] * i;
        }
    }
}

int main() {
    backtrack(0);

    cout << bestW << endl << bestV << endl;
    for (int i = 0; i < N; i++) cout << bestX[i] << " ";
    cout << endl;
    return 0;
}
