#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int index;
    int value;

    int left() { return 2 * index + 1; }
    int right() { return 2 * index + 2; }
};

TreeNode tree[100];

int main() {
    for (int i = 0; i <= 14; i++) {
        tree[i].index = i;
        tree[i].value = i;
    }
    return 0;
}