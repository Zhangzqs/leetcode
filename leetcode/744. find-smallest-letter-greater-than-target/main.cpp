#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size() - 1;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (letters[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return letters[left];
    }
};

int main() {
    vector<char> vec{'c', 'f', 'j'};
    char target = 'a';
    cout << Solution().nextGreatestLetter(vec, target) << endl;
    return 0;
}