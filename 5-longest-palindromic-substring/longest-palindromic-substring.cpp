class Solution {
public:
    string longestPalindrome(string s) {
        int n =s.length();
        if (n == 0) return "";
        vector<vector<int>> dp(n,vector<int>(n, 0));
        int maxi=1;
        int start=0;
        for (int d = 0; d < n; d++) {
            for (int i=0, j=i+d;j<n;i++,j++) {
                if (i==j) {
                    dp[i][j] = 1; 
                } 
                else if (d==1) {
                    dp[i][j]=(s[i]==s[j]) ? 2 : 0;
                } 
                else {
                    if (s[i] == s[j] && dp[i+1][j-1] != 0) {
                        dp[i][j] = 2 + dp[i+1][j-1];
                    } else {
                        dp[i][j] = 0;
                    }}
                if (dp[i][j] > maxi) {
                    maxi = dp[i][j];
                    start = i;
                }}}
        return s.substr(start, maxi);
    }
};
