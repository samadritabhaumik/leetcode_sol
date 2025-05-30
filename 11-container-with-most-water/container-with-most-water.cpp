class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1,maxi=0;
        while(left<right){
           int w=right-left;
        int h=min(height[left],height[right]);
        int curr=w*h;
        maxi=max(maxi,curr);
        height[left]<height[right] ? left++ : right-- ;
        }
        return maxi;
    }
};