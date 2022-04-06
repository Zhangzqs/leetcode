#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    string longestPalindrome(string s) {}
};

bool isPalindrome(string& s, int start, int end) {
    int left = start;
    int right = end;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    string s = "babad";
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            cout << s.substr(i, j + 1) << ": " << isPalindrome(s, i, j) << endl;
        }
    }
    return 0;
}