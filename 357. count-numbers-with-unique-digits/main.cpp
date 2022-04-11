#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    // 只有d位数的情况
    int f(int t) {
        int ret = 9;
        for (int i = 2; i <= t; i++) {
            ret = ret * (9 - i + 2);
        }
        return ret;
    }

    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 2;
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 10;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + f(i);
        }
        return dp[n];
    }
};

class Solution1 {
   public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp{1,     10,     91,     739,     5275,
                       32491, 168571, 712891, 2345851, 5611771};
        return dp[n];
    }
};

int main() {
    cout << Solution().countNumbersWithUniqueDigits(9);
    return 0;
}