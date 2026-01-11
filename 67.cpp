class Solution {
public:
    string reverse(string s) {
        string ss(s.length(), ' ');
        for (int i = 0; i < s.length(); i++) {
            ss[i] = s[s.length() - i - 1];
        }
        return ss;
    }

    string addBinary(string a, string b) {
        int CF = 0;
        a = reverse(a);
        b = reverse(b);

        int len = max(a.length(), b.length());
        string c(len, '0');

        for (int i = 0; i < len; i++) {
            int x = (i < a.length() ? a[i] - '0' : 0);
            int y = (i < b.length() ? b[i] - '0' : 0);

            int sum = x + y + CF;
            c[i] = (sum % 2) + '0';
            CF = sum / 2;
        }

        if (CF) c.push_back('1');

        return reverse(c);
    }
};
