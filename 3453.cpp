class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e18, high = -1e18;
        for (auto& s : squares) {
            low = min(low, (double)s[1]);
            high = max(high, (double)s[1] + s[2]);
        }

        for (int it = 0; it < 80; it++) {
            double mid = (low + high) / 2.0;
            double up = 0.0, down = 0.0;

            for (auto& s: squares) {
                double y = s[1], l = s[2];
                double top = y + l;
                if (top <= mid) {
                    down += l * l;
                } else if (y >= mid) {
                    up += l * l;
                } else {
                    down += l * (mid - y);
                    up += l * (top - mid);
                }
            }

            if (down >= up) high = mid;
            else low = mid;
        }
        return high;
    }
};
