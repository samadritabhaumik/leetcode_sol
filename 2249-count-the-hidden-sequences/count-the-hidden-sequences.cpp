class Solution {
 #define ll long long
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        ll gap=0,mini=0,maxi=0,curr=0;
        for(int& ele: differences){
            curr+=ele;
            mini=min(mini,curr);
            maxi=max(maxi,curr);
        }
        int count=(upper-lower)-(maxi-mini) + 1;
        return count>0?count : 0;
    }
};