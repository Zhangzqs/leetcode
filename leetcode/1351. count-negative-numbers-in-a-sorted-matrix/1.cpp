#include <bits/stdc++.h>
using namespace std;

// TODO
class Solution {
   public:
    int countNegatives(vector<vector<int>>& grid) {
        int top = 0;
        for (int i = 0; i < grid[0].size(); i++) {
            if (grid[0][i] > 0)
                top++;
            else
                break;
        }
        int left = 0;
        for (int i = 0; i < grid.size(); i++) {
            if (grid[i][0] > 0)
                left++;
            else
                break;
        }
        int right = 0;
        for (int i = 0; i < grid.size(); i++) {
            if (grid[i][top - 1] > 0)
                right++;
            else
                break;
        }
        int bottom = 0;
        for (int i = 0; i < grid[left - 1].size(); i++) {
            if (grid[left - 1][i] > 0)
                bottom++;
            else
                break;
        }
        int all = top * left;
        int small = 0;
        if (grid[left - 1][top - 1] < 0) {
            for (int i = left - 1; i >= right; i--) {
                for (int j = top - 1; j >= bottom; j--) {
                    if (grid[i][j] < 0) {
                        small++;
                    } else {
                        break;
                    }
                }
                if (grid[i][grid[i].size() - 1] >= 0) break;
            }
        }
        return all - small;
    }
};
int main() {
    vector<vector<int>> mat{
        {4, 3, 2, -1},
        {3, 2, 1, -1},
        {1, 1, -1, -2},
        {-1, -1, -2, -3},
    };
    Solution().countNegatives(mat);
    return 0;
}