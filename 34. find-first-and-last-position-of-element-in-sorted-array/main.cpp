#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto begin_it = lower_bound(nums.begin(), nums.end(), target);
        auto end_it = upper_bound(nums.begin(), nums.end(), target);
        int i1 = begin_it - nums.begin();
        int i2 = end_it - nums.begin() - 1;

        if ((i1 < 0 || i1 >= nums.size()) || nums[i1] != target) i1 = -1;
        if ((i1 < 0 || i2 >= nums.size()) || nums[i2] != target) i2 = -1;
        return {i1, i2};
    }
};

int main() {
    vector<int> vec{2, 2};
    int target = 3;
    auto ret = Solution().searchRange(vec, target);
    int i1 = ret[0];
    int i2 = ret[1];
    cout << i1 << ", " << i2 << endl;
    return 0;
}