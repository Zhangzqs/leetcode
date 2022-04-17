#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
using ll = long long;

struct Frac {
    ll a;  // 分子
    ll b;  // 分母

    static Frac fromInput() {
        ll a, b;
        scanf("%lld/%lld", &a, &b);
        return {a, b};
    }

    void output() {
        ll n = a / b;
        double nf = double(a) / double(b);
        if (nf < 0) printf("-");

        if (a < 0) a = -a;
        if (b < 0) b = -b;
        if (n < 0) n = -n;

        if (n == 0) {
            printf("%lld/%lld", a, b);
            return;
        }
        ll top = a - n * b;
        if (top != 0) {
            printf("%lld %lld/%lld", n, top, b);
            return;
        } else {
            printf("%lld", n);
            return;
        }
    }

    Frac add(const Frac& o) {
        ll under = b * o.b;
        ll top1 = a * o.b;
        ll top2 = o.a * b;
        ll top = top1 + top2;
        ll gcd = __gcd(top, under);
        return {top / gcd, under / gcd};
    }
};

int main() {
    int N;
    scanf("%d", &N);
    Frac f1 = Frac::fromInput();
    for (int i = 1; i < N; i++) {
        Frac f = Frac::fromInput();
        f1 = f1.add(f);
    }
    f1.output();
    return 0;
}