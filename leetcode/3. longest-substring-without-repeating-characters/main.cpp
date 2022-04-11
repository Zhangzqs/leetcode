#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    unordered_set<char> cs{};
    int longestSubstring(const string::iterator& start,
                         const string::iterator& end) {
        string::iterator it = start;
        while (it != end) {
            char ch = *(it++);
            // 找到了
            if (cs.find(ch) != cs.end()) return cs.size();
            cs.insert(ch);
        }
        return cs.size();
    }
    int lengthOfLongestSubstring(string s) {
        int m = 0;
        for (string::iterator it = s.begin(); it != s.end(); it++) {
            m = max(m, longestSubstring(it, s.end()));
            cs.clear();
        }
        return m;
    }
};

int main() {
    int a = Solution().lengthOfLongestSubstring("abcabcbb");
    cout << a << endl;
    return 0;
}