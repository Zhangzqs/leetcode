#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int specialArray(vector<int>& nums) {
        // x最小值为0, 最大值为nums.size()
        int left = 0, right = nums.size();
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            int val = countGreater(nums, mid);
            if (val == mid) return mid;
            if (val > mid)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }

    int countGreater(vector<int>& nums, int x) {
        int count = 0;
        for (int& num : nums) {
            if (num >= x) count++;
        }
        return count;
    }
};

void test(vector<int> nums, int expect) {
    int actual = Solution().specialArray(nums);
    cout << "actual: " << actual << "|expect: " << expect << endl;
    assert(actual == expect);
}

int main() {
    test({3, 5}, 2);
    test({0, 0}, -1);
    test({0, 4, 3, 0, 4}, 3);
    test({3, 6, 7, 7, 0}, -1);
    return 0;
}