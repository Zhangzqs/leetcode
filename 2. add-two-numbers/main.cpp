#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void displayList(ListNode *node) {
    for (ListNode *it = node; it != nullptr; it = it->next) {
        cout << it->val << ", ";
    }
    cout << endl;
}

ListNode *vecToList(const vector<int> &vec) {
    ListNode *header = new ListNode;

    ListNode *it = header;
    for (auto i : vec) {
        it->next = new ListNode(i);
        it = it->next;
    }
    return header->next;
}

class Solution {
   public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ret = new ListNode(l1->val + l2->val);

        ListNode *it1 = l1, *it2 = l2;
        ListNode *it3 = ret;
        // 只要两个链表都没有遍历到最后
        while (it1->next != nullptr && it2->next != nullptr && it3 != nullptr) {
            it1 = it1->next;
            it2 = it2->next;
            it3->next = new ListNode(it1->val + it2->val);
            it3 = it3->next;
        }
        while (it1->next != nullptr) {
            it1 = it1->next;
            it3->next = new ListNode(it1->val);
            it3 = it3->next;
        }
        while (it2->next != nullptr) {
            it2 = it2->next;
            it3->next = new ListNode(it2->val);
            it3 = it3->next;
        }

        int carry = 0;
        for (ListNode *it = ret; it != nullptr; it = it->next) {
            it->val += carry;
            carry = it->val / 10;
            it->val -= carry * 10;

            if (it->next == nullptr && carry != 0) {
                it->next = new ListNode(carry);
                carry = 0;
            }
        }
        return ret;
    }
};

int main() {
    ListNode *l1 = vecToList({2, 4, 9});
    ListNode *l2 = vecToList({5, 6, 4, 9});
    displayList(l1);
    displayList(l2);
    ListNode *result = Solution().addTwoNumbers(l1, l2);
    displayList(result);
    return 0;
}
