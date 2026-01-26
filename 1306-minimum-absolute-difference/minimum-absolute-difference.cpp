class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
      sort(begin(arr),end(arr));
        vector<vector<int>> res;
        int n=arr.size();
        int minDiff = INT_MAX;
        for(int i = 1; i < n; i++) {
            int diff = arr[i] - arr[i-1];
            minDiff = min(diff, minDiff);
        }
        for(int i = 1; i<n; i++) {
            int diff=arr[i]-arr[i-1];
            if(diff == minDiff) {
                res.push_back({arr[i-1], arr[i]});
            }
        }
        return res;   
    }
};