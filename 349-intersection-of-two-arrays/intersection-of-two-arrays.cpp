class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(),nums1.end());
        unordered_set<int> common;
        for(int i:nums2){
            if(s.contains(i)) common.insert(i);
        }
                    vector<int> res(common.begin(),common.end()); 
        return res;
    }
};