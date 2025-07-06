class FindSumPairs {
    vector<int> arr1,arr2;
    unordered_map<int,int> freq;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1;
        arr2 = nums2;
        for(int ele: nums2)
            freq[ele]++;
    } 
    void add(int index, int val) {
        freq[arr2[index]]--;
        arr2[index] += val;
        freq[arr2[index]]++;
    } 
    int count(int tot) {
        int res = 0;
        for(int ele: arr1)
            if(freq.count(tot-ele))
                res += freq[tot-ele];
        return res;
    }
};