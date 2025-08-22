class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int minr=m;
        int maxr=-1;
        int minc=n;
        int maxc=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    minr=min(minr,i);
                    maxr=max(maxr,i);
                    minc=min(minc,j);
                    maxc=max(maxc,j);
                }
            }
        }
        return (maxr-minr+1)*(maxc-minc+1);
    }
};