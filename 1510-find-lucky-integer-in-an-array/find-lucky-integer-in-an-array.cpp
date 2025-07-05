class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        int maxi=-1;
        for(int i:arr){
        mp[i]++;
        }
        for(auto j:mp)
        {
        if(j.first==j.second)
        maxi=max(maxi,j.first);
        }
        return maxi;
    }
};