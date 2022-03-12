#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

struct Node {
    int leftIndex = -1;
    int rightIndex = -1;
    int parent = -1;

    void display() {
        cout << "left: " << leftIndex << ", "
             << "right: " << rightIndex << ", "
             << "parent: " << parent << endl;
    }
};
class Solution {
   public:
    void makeBinaryTree(vector<int> &parents, vector<Node> &nodes) {
        int nodeCnt = parents.size();
        for (int i = 0; i < nodeCnt; i++) {
            int parent = parents[i];
            nodes[i].parent = parent;
            if (parent == -1) continue;
            // i 表示当前节点，parent表示当前节点的父节点
            if (nodes[parent].leftIndex == -1) {
                nodes[parent].leftIndex = i;
            } else {
                nodes[parent].rightIndex = i;
            }
        }
    }

    int cntNodeNum(vector<Node> &nodes, int index) {
        int cnt = 0;
        if (index == -1) return cnt;
        function<void(int)> fun = [&](int i) {
            if (nodes[i].leftIndex != -1) fun(nodes[i].leftIndex);
            cnt++;
            if (nodes[i].rightIndex != -1) fun(nodes[i].rightIndex);
        };
        fun(index);
        return cnt;
    }

    ll deleteNodeIndex(vector<Node> &tree, int index) {
        Node &node = tree[index];
        if (node.parent == -1) {
            // 无父亲，即为根节点
            ll leftCnt = cntNodeNum(tree, node.leftIndex);
            ll rightCnt = tree.size() - leftCnt - 1;
            return (leftCnt != 0 ? leftCnt : 1) *
                   (rightCnt != 0 ? rightCnt : 1);
        }

        if (node.leftIndex == -1 && node.rightIndex == -1) {
            // 叶子
            return tree.size() - 1;
        }

        ll leftTreeCnt = cntNodeNum(tree, node.leftIndex);
        ll rightTreeCnt = cntNodeNum(tree, node.rightIndex);
        ll parentTreeCnt = tree.size() - leftTreeCnt - rightTreeCnt - 1;

        ll ret = 1;
        if (leftTreeCnt != 0) ret *= leftTreeCnt;
        if (rightTreeCnt != 0) ret *= rightTreeCnt;
        if (parentTreeCnt != 0) ret *= parentTreeCnt;
        return ret;
    }

    int countHighestScoreNodes(vector<int> &parents) {
        vector<Node> tree(parents.size());
        makeBinaryTree(parents, tree);

        ll maxScore = 0;
        int ans = 0;
        for (int i = 0; i < parents.size(); i++) {
            ll score = deleteNodeIndex(tree, i);
            if (score == maxScore) {
                ans++;
            } else if (score > maxScore) {
                maxScore = score;
                ans = 1;
            }
        }

        return ans;
    }
};

int main() {
    auto s = Solution();

    vector<int> parents1{-1, 2, 0, 2, 0}, parents2{-1, 2, 0},
        parents3{-1, 3, 3, 5, 7, 6, 0, 0};

    assert(s.countHighestScoreNodes(parents1) == 3);
    assert(s.countHighestScoreNodes(parents2) == 2);
    assert(s.countHighestScoreNodes(parents3) == 2);
    return 0;
}