class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();
        set<int> st;
        for(auto it:candyType)
        st.insert(it);
        int m=st.size();
        return min(n/2,m);
    }
};