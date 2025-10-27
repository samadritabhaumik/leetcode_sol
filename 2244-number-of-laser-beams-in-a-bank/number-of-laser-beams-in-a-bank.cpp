class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0;
        int n=bank.size();
        int m=bank[0].size();
        int prev=0;
        for (int i=0;i<n;i++) {
            int curr=0;
            for (int j=0;j<m;j++) {
                curr += bank[i][j] - '0';
            }
            if (curr != 0) {
                ans += prev * curr;
                prev = curr;
            }
        }
        return ans;
    }
};