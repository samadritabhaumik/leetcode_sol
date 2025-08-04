class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int last=-1;
        int secondl=-1;
        int count=0;     
        int curr=0;     
        int best=0;
        for (int f:fruits) {
            if (f==last || f==secondl) {
                curr+=1;
            } else {
                curr=count+ 1;
            }
            if (f==last) {
                count+=1;
            } else {
                count=1;
                secondl=last;
                last=f;
            }
            best=max(best,curr);
        }
        return best;
    }
};

