#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

Node* newTree() {
    return new Node(1, {
                           new Node(2),
                           new Node(3,
                                    {
                                        new Node(6),
                                        new Node(7,
                                                 {
                                                     new Node(11,
                                                              {
                                                                  new Node(14),
                                                              }),

                                                 }),
                                    }),
                           new Node(4,
                                    {
                                        new Node(8,
                                                 {
                                                     new Node(12),
                                                 }),
                                    }),
                           new Node(5,
                                    {
                                        new Node(9, {new Node(13)}),
                                        new Node(10),
                                    }),
                       });
}

class Solution {
   public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return {};
        vector<vector<Node*>> ret;
        vector<vector<int>> ret2;
        ret.push_back({root});
        ret2.push_back({root->val});
        while (!ret.back().empty()) {
            auto& backLayer = ret.back();
            vector<Node*> newLayer;
            vector<int> newLayerValue;
            for (Node* layerNode : backLayer) {
                for (Node*& child : layerNode->children) {
                    newLayerValue.push_back(child->val);
                    newLayer.push_back(child);
                }
            }
            if (!newLayerValue.empty()) ret2.push_back(newLayerValue);
            ret.push_back(newLayer);
        }
        return ret2;
    }
};

class Solution1 {
   public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return {};
        vector<vector<int>> ret;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> tmp;
            int s = q.size();
            while (s--) {
                Node* t = q.front();
                q.pop();
                tmp.push_back(t->val);
                for (Node*& child : t->children) {
                    q.push(child);
                }
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};

void output(vector<vector<int>> result) {
    for (vector<int>& line : result) {
        for (int& e : line) {
            cout << e << " ";
        }
        cout << endl;
    }
}

int main() {
    Node* root = newTree();
    auto result = Solution1().levelOrder(root);
    output(result);
    return 0;
}