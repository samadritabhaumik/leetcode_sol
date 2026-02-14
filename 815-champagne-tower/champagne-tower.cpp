class Solution {
public:
 double t[101][101];
    double solve(int num,int i,int j){
        if(i<0 || j>i || j<0)
            return 0.0;
        if(i==0 && j==0)
            return t[i][j]=num;
        if(t[i][j]!=-1)
            return t[i][j];
        double l=(solve(num,i-1,j-1)-1)/2.0;
        double r=(solve(num,i-1,j)-1)/2.0;
         if(l < 0)
            l = 0.0;
        if(r < 0)
            r = 0.0;
        return t[i][j] = l + r;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
      for(int i=0;i<101; i++) {
            for(int j = 0; j<101; j++) {
                t[i][j] = -1;
            }
        }  
        return min(1.0, solve(poured, query_row, query_glass));  
    }
};