#include <bits/stdc++.h>

using namespace std;

const int JM_TYPE = 0;
const int LJX_TYPE = 1;

struct P {
    int index;
    int type;

    static P fromInput() {
        string ps;
        cin >> ps;
        if (ps[0] >= '0' && ps[0] <= '9') {
            return {
                atoi(ps.c_str()),
                JM_TYPE,
            };
        } else {
            return {
                atoi(ps.c_str() + 1),
                LJX_TYPE,
            };
        }
    }
};

struct Line {
    P p1;
    P p2;
    int dist;
    static Line fromInput() {
        P p1 = P::fromInput();
        P p2 = P::fromInput();
        int dist;
        cin >> dist;
        return {p1, p2, dist};
    }
};

int main() {
    // 居民点的个数(<=10**3)
    int N;
    cin >> N;
    // 垃圾箱候选地点的个数(<=10)
    int M;
    cin >> M;
    // 居民点和垃圾箱候选地的道路条数(<=10**4)
    int K;
    cin >> K;
    // 居民点与垃圾箱之间不能超过的最大距离
    int Ds;
    cin >> Ds;
    vector<Line> lines;
    lines.reserve(K);
    for (int i = 0; i < K; i++) {
        lines.push_back(Line::fromInput());
    }
    return 0;
}