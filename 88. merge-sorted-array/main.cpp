#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res{};
        res.reserve(nums1.size() + nums2.size());
        int p1 = 0, p2 = 0;
        while (p1 < m && p2 < n) {
            if (nums1[p1] < nums2[p2]) {
                res.push_back(nums1[p1++]);
            } else {
                res.push_back(nums2[p2++]);
            }
        }
        while (p1 < m) res.push_back(nums1[p1++]);
        while (p2 < n) res.push_back(nums2[p2++]);
        nums1 = res;
    }
};

void display(const vector<int>& nums) {
    for (const int& i : nums) {
        cout << i << ", ";
    }
    cout << endl;
}

int main() {
    vector<int> num1{1, 3, 5};
    vector<int> num2{2, 4};
    Solution().merge(num1, num1.size(), num2, num2.size());
    display(num1);
    return 0;
}