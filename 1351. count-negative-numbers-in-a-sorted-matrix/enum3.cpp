#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] >= 0)
                    cnt++;
                else
                    break;
            }
            if (grid[i][0] < 0) break;
        }
        return grid.size() * grid[0].size() - cnt;
    }
};
