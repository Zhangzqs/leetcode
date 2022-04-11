#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size() - 1; i++) {
            int a = numbers[i];
            int b = target - a;
            int targetIndex =
                findElement(numbers, i + 1, numbers.size() - 1, b);
            if (numbers[targetIndex] == b) return {i + 1, targetIndex + 1};
        }
        return {0, 0};
    }

    int findElement(vector<int>& vec, int from, int to, int target) {
        int left = from, right = to;
        while (left < right) {
            int mid = (right - left) / 2 + left;
            if (vec[mid] < target) {
                // 中间偏小,向右找
                left = mid + 1;
            } else if (vec[mid] > target) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return left;
    }
};

int main() {
    int target = 9;
    vector<int> vec{2, 7, 11, 15};
    auto ret = Solution().twoSum(vec, target);
    cout << "[" << ret[0] << ", " << ret[1] << "]" << endl;
    return 0;
}