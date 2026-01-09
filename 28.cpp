class Solution {
public:
    int strStr(string haystack, string needle) {
        haystack = '0' + haystack;
        needle = '0' + needle;
        int kmp[10005];
        int pos = 0;
        for (int i = 2; i < needle.length(); i++) {
            while (pos && needle[i] != needle[pos + 1]) pos = kmp[pos];
            if (needle[pos + 1] == needle[i]) pos++;
            kmp[i] = pos;
        }

        pos = 0;
        for (int i = 1; i < haystack.length(); i++) {
            while (pos && haystack[i] != needle[pos + 1]) pos = kmp[pos];
            if (needle[pos + 1] == haystack[i]) pos++;
            if (pos == needle.length() - 1) return i - needle.length() + 1;
        }

        return -1;
    }
};