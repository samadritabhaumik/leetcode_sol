class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i=0;i<=num;i++){
            int n=i;
            string s=to_string(i);
            reverse(s.begin(),s.end());
            if(n+stoi(s)==num)
            return true;
        }
        return false;
    }
};