class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
string solve=countAndSay(n-1);
string res="";
for(int i=0;i<solve.length();i++){
    char ch=solve[i];
    int count=1;
    while(i<solve.length()-1 && solve[i]==solve[i+1]){
        count++;
        i++;
    }
    res+=to_string(count)+string(1,ch);
}
return res;
    }
};