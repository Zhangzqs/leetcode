#include <bits/stdc++.h>

#include "node.h"
using namespace std;

// 二叉树的先序遍历
vector<int> preOrderTraversalRecursively(TreeNode *root) {
    vector<int> ret;
    function<void(TreeNode *)> f = [&](TreeNode *node) {
        if (node == nullptr) return;
        ret.push_back(node->val);
        f(node->left);
        f(node->right);
    };
    f(root);
    return ret;
}

vector<int> preOrderTraversalIteratively(TreeNode *root) {
    vector<int> ret;
    stack<TreeNode *> st{};
    st.push(root);
    while (!st.empty()) {
        TreeNode *t = st.top();
        st.pop();
        ret.push_back(t->val);
        // 由于下一步需要访问左孩子了,
        // 故栈顶元素必须是t->left
        if (t->right != nullptr) st.push(t->right);
        if (t->left != nullptr) st.push(t->left);
    }
    return ret;
}

// 二叉树中序遍历
vector<int> inOrderTraversalRecursively(TreeNode *root) {
    vector<int> ret;
    function<void(TreeNode *)> f = [&](TreeNode *node) {
        if (node == nullptr) return;
        f(node->left);

        ret.push_back(node->val);
        f(node->right);
    };
    f(root);
    return ret;
}

vector<int> inOrderTraversalIteratively(TreeNode *root) {
    vector<int> ret;
    stack<TreeNode *> st;
    TreeNode *cur = root;
    while (cur != nullptr || !st.empty()) {
        if (cur != nullptr) {
            st.push(cur);
            cur = cur->left;
        } else {
            cur = st.top();
            st.pop();
            ret.push_back(cur->val);
            cur = cur->right;
        }
    }

    return ret;
}

// 二叉树后序遍历
vector<int> postOrderTraversalRecursively(TreeNode *root) {
    vector<int> ret;
    function<void(TreeNode *)> f = [&](TreeNode *node) {
        if (node == nullptr) return;
        f(node->left);
        f(node->right);
        ret.push_back(node->val);
    };
    f(root);
    return ret;
}

vector<int> postOrderTraversalIterative(TreeNode *root) {
    int arr[100];
    int len = 0;
    stack<TreeNode *> st{};
    st.push(root);
    while (!st.empty()) {
        TreeNode *t = st.top();
        st.pop();
        arr[len++] = t->val;
        // 由于下一步需要访问左孩子了,
        // 故栈顶元素必须是t->left

        if (t->left != nullptr) st.push(t->left);
        if (t->right != nullptr) st.push(t->right);
    }
    vector<int> ret;
    ret.reserve(len);
    for (int i = len - 1; i >= 0; i--) ret.push_back(arr[i]);
    return ret;
}

vector<int> layerOrderTraversal(TreeNode *root) {
    vector<int> ret;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *f = q.front();
        q.pop();
        ret.push_back(f->val);
        if (f->left != nullptr) q.push(f->left);
        if (f->right != nullptr) q.push(f->right);
    }
    return ret;
}

void output(TreeNode *root) {
    function<void(TreeNode *, int)> f = [&](TreeNode *node, int deep) {
        if (node == nullptr) return;
        for (int i = 0; i < deep - 1; i++) cout << "    ";
        if (deep != 0) cout << "|___";
        cout << node->val << endl;
        f(node->left, deep + 1);
        f(node->right, deep + 1);
    };
    f(root, 0);
}

void output(vector<int> &vec) {
    for (int &v : vec) cout << v << ", ";
}

void output(function<vector<int>(TreeNode *)> strategy, TreeNode *root) {
    vector<int> vec = strategy(root);
    output(vec);
}

void output(string s, function<vector<int>(TreeNode *)> strategy,
            TreeNode *root) {
    cout << s << endl;
    output(strategy, root);
    cout << endl;
}

int main() {
    TreeNode *root = new TreeNode(  //
        0,
        new TreeNode(1,  //
                     new TreeNode(3),
                     new TreeNode(4,                  //
                                  new TreeNode(7),    //
                                  new TreeNode(8))),  //
        new TreeNode(2,                               //
                     new TreeNode(5,                  //
                                  nullptr,            //
                                  new TreeNode(9)),
                     new TreeNode(6,  //
                                  new TreeNode(10))));
    output(root);
    output("先序遍历递归: ", preOrderTraversalRecursively, root);
    output("先序遍历非递归: ", preOrderTraversalIteratively, root);
    output("中序遍历递归: ", inOrderTraversalRecursively, root);
    output("中序遍历非递归: ", inOrderTraversalIteratively, root);
    output("后序遍历递归: ", postOrderTraversalRecursively, root);
    output("后序遍历非递归: ", postOrderTraversalIterative, root);
    output("层序遍历: ", layerOrderTraversal, root);
    return 0;
}