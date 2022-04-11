#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        list<char> a{};
        int ans = 0;
        for (char& c : s) {
            while (find(a.begin(), a.end(), c) != a.end()) {
                a.erase(a.begin());
            }
            a.push_back(c);
            ans = max(ans, int(a.size()));
        }
        return ans;
    }
};

int main() {
    int a = Solution().lengthOfLongestSubstring("abcabcbb");
    cout << a << endl;
    return 0;
}