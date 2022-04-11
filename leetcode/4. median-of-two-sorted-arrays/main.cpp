#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // 归并排序的方案
    vector<int> concat(vector<int>& num1, vector<int>& num2) {
        vector<int> result{};
        result.reserve(num1.size() + num2.size());
        int p1 = 0, p2 = 0;
        while (p1 < num1.size() && p2 < num2.size()) {
            if (num1[p1] <= num2[p2]) {
                result.push_back(num1[p1]);
                p1++;
            } else {
                result.push_back(num2[p2]);
                p2++;
            }
        }
        while (p1 < num1.size()) {
            result.push_back(num1[p1]);
            p1++;
        }
        while (p2 < num2.size()) {
            result.push_back(num2[p2]);
            p2++;
        }
        return move(result);
    }

    double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
        vector<int> result = concat(num1, num2);
        int half = result.size() / 2;
        if (result.size() % 2 == 1) {
            return double(result[half]);
        } else {
            return double(result[half] + result[half - 1]) / 2.0;
        }
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
    display(Solution().concat(num1, num2));
    int result = Solution().findMedianSortedArrays(num1, num2);
    cout << result << endl;
    return 0;
}