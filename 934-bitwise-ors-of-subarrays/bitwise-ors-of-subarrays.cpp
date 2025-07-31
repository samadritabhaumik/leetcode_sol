class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
         unordered_set<int> res, prev;  
        for (int num : arr) {
            unordered_set<int> curr;
            curr.insert(num);
            for (int i:prev) {
                curr.insert(i|num);
            }
            prev=curr;
            res.insert(curr.begin(), curr.end());}  
        return res.size();
    }
};