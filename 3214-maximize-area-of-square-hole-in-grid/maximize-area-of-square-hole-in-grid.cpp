class Solution {
public:
    int getMaxArea(int n, vector<int>& bars) {
        int ans=2;
        sort(bars.begin(),bars.end());
        int count=1;
        for (int i=1;i<bars.size();i++) {
            if (bars[i]-bars[i-1]==1) {
                count++;
                ans=max(ans,count+1);
            } else {
                count=1;
            }
        }
        if (count==1 && bars.back()==n-1) {
            count++;
            ans = max(ans, count);
        }
        return ans;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {
        int X = getMaxArea(n,hBars);
        int Y = getMaxArea(m,vBars);
       int side=min(X,Y);
       int area=side*side;
       return area;
    }
};