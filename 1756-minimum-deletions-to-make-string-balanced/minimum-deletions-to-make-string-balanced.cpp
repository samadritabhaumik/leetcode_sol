class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        int countA=0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') {
                countA++;
            }
        }
        int mini = min(countA, n - countA);
        int countB=0;
        for (int i = 1; i <= n; i++) {
            if(s[i-1]=='a'){
                countA--;
            }
            if(s[i-1]=='b'){
                countB++;
            }
            mini = min(mini, countA+countB);
        }
        return mini;
    }
};