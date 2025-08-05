class Solution {
public:
    int numOfUnplacedFruits(std::vector<int>& fruits,std::vector<int>& baskets) {
                    int n=fruits.size();
    vector<bool> res(n,false);
        int un=0;
        for(int i=0;i<n;i++){
            bool placed=false;
                    for(int j=0;j<n;j++){
                    if(!res[j] && baskets[j]>=fruits[i]){
                        res[j]=true;
                        placed=true;
                        break;
                    }}
            if(!placed) un++;
        }
        return un;
    }
};