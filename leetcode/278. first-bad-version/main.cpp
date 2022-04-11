#include <bits/stdc++.h>

using namespace std;
bool isBadVersion(int version) { return version >= 4; }

class Solution {
   public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (isBadVersion(mid)) {
                // 在左边或mid自身
                right = mid - 1;
            } else {
                // 一定在右边
                left = mid + 1;
            }
        }
        // left>right
        return left;
    }
};
int main() {
    cout << Solution().firstBadVersion(5) << endl;
    return 0;
}