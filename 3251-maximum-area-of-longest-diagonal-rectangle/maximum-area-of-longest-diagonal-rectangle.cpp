class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        long long maxd=-1;
        long long maxi=0;
        for(auto &i:dimensions){
             long long l=i[0],w=i[1];
            long long diag=l*l+w*w;
            long long area=l*w;
            if(diag>maxd){
                maxd=diag;
                maxi=area;
            }
            else if(maxd==diag){
                maxi=max(maxi,area);
            }
        }
        return (int)maxi;
    }
};