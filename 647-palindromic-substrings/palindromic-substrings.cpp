class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n,vector<bool>(n, false));
        int count=0;
        for (int d=0;d<n;d++) {
            for (int i=0,j=i+d;j<n;i++,j++) {
                if (i==j) {
                    dp[i][j] = true;
                } else if (s[i]==s[j]) {
                    if (j-i==1 || dp[i+1][j-1]) {
                        dp[i][j]=true;
                    }}
                if (dp[i][j]) count++;
            }}
        return count;
    }
};
