
/*
假设有 n 台超级洗衣机放在同一排上。开始的时候，每台洗衣机内可能有一定量的衣服，也可能是空的。

在每一步操作中，你可以选择任意 m (1 <= m <= n) 台洗衣机，与此同时将每台洗衣机的一件衣服送到相邻的一台洗衣机。

给定一个整数数组 machines 代表从左至右每台洗衣机中的衣物数量，请给出能让所有洗衣机中剩下的衣物的数量相等的 最少的操作步数 。如果不能使每台洗衣机中衣物的数量相等，则返回 -1 。
(衣服必须能够均分，如果不能够均分，那么就返回-1)
*/

/*
示例 1：

输入：machines = [1,0,5]
输出：3
解释：
第一步:    1     0 <-- 5    =>    1     1     4
第二步:    1 <-- 1 <-- 4    =>    2     1     3
第三步:    2     1 <-- 3    =>    2     2     2

[1,0,5]-[2,2,2]=[-1,-2,3]
(负数为移入，正数为移出)
一次只能移动一件衣服
若要使洗衣机1到达平衡，需要从2中移出1件，然后得到[0,-3,3]
若要使洗衣机2到达平衡，需要从3中移出3件，即得到[0,0,0]


示例 2：

输入：machines = [0,3,0]
输出：2
解释：
第一步:    0 <-- 3     0    =>    1     2     0
第二步:    1     2 --> 0    =>    1     1     1
[0,3,0]-[1,1,1]=[-1,2,-1]
从2移1得[0,1,-1]
从3移-1得[0,0,0]

示例 3：

输入：machines = [0,2,0]
输出：-1
解释：
不可能让所有三个洗衣机同时剩下相同数量的衣物。
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMinMoves(vector<int> &machines)
    {
        // 衣服总数
        int sum = accumulate(machines.begin(), machines.end(), 0);
        // 洗衣机总数
        int n = machines.size();

        // 衣服总数与洗衣机总数需要能够整除才能够均分
        if (sum % n != 0)
        {
            return -1;
        }

        int avg = sum / n;

        int balance = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int mov = machines[i] - avg;
            balance += mov;

            ans = max(ans, max(mov, abs(balance)));
        }
        return ans;
    }
};

int main()
{
    auto s = Solution();
    vector<int> v1{0, 3, 0};
    int a1 = 2;
    vector<int> v2{0, 2, 0};
    int a2 = -1;
    vector<int> v3{1, 0, 5};
    int a3 = 3;

    assert(s.findMinMoves(v1) == a1);
    assert(s.findMinMoves(v2) == a2);
    assert(s.findMinMoves(v3) == a3);
    return 0;
}