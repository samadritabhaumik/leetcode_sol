class Solution {
    using ll = long long;
    vector<ll> seg_tree;
    void update(ll st_idx,ll start,ll end,ll& query_idx){
        if(end<query_idx or start>query_idx)
            return;
        if(start==end){
            seg_tree[st_idx]++;
            return;
        }
        ll mid = start + (end-start)/2;
        update(2*st_idx,start,mid,query_idx);
        update(2*st_idx+1,mid+1,end,query_idx);
        seg_tree[st_idx] = seg_tree[2*st_idx] + seg_tree[2*st_idx+1];
    }
    int rangeSumQuery(ll st_idx,ll start,ll end,ll qs,ll qe){
        if(qs>end or qe<start)  return 0;
        if(start>=qs and end<=qe)   return seg_tree[st_idx];
        ll mid = start + (end-start)/2;
        ll left_sum = rangeSumQuery(2*st_idx,start,mid,qs,qe);
        ll right_sum = rangeSumQuery(2*st_idx+1,mid+1,end,qs,qe);
        return left_sum + right_sum;
    }
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        ll n = nums1.size();
        seg_tree = vector<ll>(4*n+1,0);
        unordered_map<ll,ll> ans;
        for(ll i=0;i<n;++i)
            ans[nums2[i]] = i;
        update(1,0,n-1,ans[nums1[0]]);
        ll count = 0;
        for(int i=1;i<n-1;++i){
            ll nums2_idx = ans[nums1[i]];
            ll left = rangeSumQuery(1,0,n-1,0,nums2_idx);
            ll uncommon = (i-left);
            ll right = (n-nums2_idx-1) - uncommon;
            count += left * right;
            update(1,0,n-1,nums2_idx);
        }
        return count;
    }
};