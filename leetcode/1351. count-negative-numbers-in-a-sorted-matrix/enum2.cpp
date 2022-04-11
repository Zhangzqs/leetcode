#include <bits/stdc++.h>

using namespace std;
class Solution {
   public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        for (int i = grid.size() - 1; i >= 0; i--) {
            for (int j = grid[i].size() - 1; j >= 0; j--) {
                if (grid[i][j] < 0) {
                    cnt++;
                } else {
                    break;
                }
            }
            if (grid[i][grid[i].size() - 1] >= 0) break;
        }
        return cnt;
    }
};