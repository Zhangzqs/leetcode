#include <bits/stdc++.h>

using namespace std;
class Solution {
   public:
    int mySqrt(int x) {
        // 在1和x之间搜索一个整数使得
        int left = 1;
        int right = x;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            // 搜索出的结果比target要小
            if (mid * mid < x) {
                // 往大了搜
                left = mid + 1;
            } else if (mid * mid == x) {
                return mid;
            } else {
                // 往小了搜
                right = mid - 1;
            }
        }
        return right;
    }
};
int main() {
    cout << Solution().mySqrt(8) << endl;
    return 0;
}