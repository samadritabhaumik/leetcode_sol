class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
       int m = spells.size();
        int n = potions.size();
        sort(begin(potions),end(potions));
        int maxi=potions[n-1];
        vector<int> answer;
        for(int i = 0; i<m; i++) {
            int spell = spells[i];
            long long mini = ceil((1.0*success)/spell);
            if(mini > maxi) {
                answer.push_back(0);
                continue;
            }
            int index=lower_bound(begin(potions),end(potions),mini)-begin(potions);
            answer.push_back(n-index);        
        } 
    return answer;
    }
};