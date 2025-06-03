class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        unordered_map<int,int> mp;
        int gcd=0;
        for(int i:deck){
            mp[i]++;
        }
         for (auto& p:mp) {
            gcd = __gcd(gcd, p.second);
        }
        return gcd>=2;
    }
};