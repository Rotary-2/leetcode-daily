class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        vector<int> v;
        while (x) {
           int y = x % 10;
            v.push_back(y);
            x /= 10;
        }
        for (int i = 0; i <= v.size() / 2; i++) {
            if (v[i] != v[v.size() - 1 - i]) return false;
        }
        return true;
    }
};