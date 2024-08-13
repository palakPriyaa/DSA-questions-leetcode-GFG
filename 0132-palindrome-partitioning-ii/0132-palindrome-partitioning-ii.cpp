class Solution {
public:
bool isPalindrome(int i, int j, string &s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}


int minPartitions(int i, int n, string &str, vector<int> &dp) {
    
    if (i == n) return 0;

    if (dp[i] != -1) return dp[i];
    int minCost = INT_MAX;
    
    
    for (int j = i; j < n; j++) {
        if (isPalindrome(i, j, str)) {
            
            int cost = 1 + minPartitions(j + 1, n, str, dp);

            minCost = min(minCost, cost);
        }
    }
    return dp[i] = minCost;
}
    int minCut(string str) {
         int n = str.size();
    vector<int> dp(n, -1);
    
    // subtracting 1 as it counts partitions, not cuts.
    return minPartitions(0, n, str, dp) - 1;
    }
};