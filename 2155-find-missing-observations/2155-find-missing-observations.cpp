class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total = mean * (n + m);
        int sm = 0;
        for (auto r : rolls)
            sm += r;
        total -= sm;
        if (total < n || total > 6 * n)
            return {};

        auto [q, r] = div(total, n);
        vector<int> res(n, q);
        fill(res.begin(), res.begin() + r, q + 1);
        return res;
    }
};