class Solution {
public:
    string solve(int n) {
        string count(10, '0');  
        while (n > 0) {
            count[n % 10]++;    
            n /= 10;           
        }
        return count;      
    }
    bool reorderedPowerOf2(int n) {
        string target = solve(n); 
        for (int i=0;i<31;++i) {  
            int power = 1 << i;          
            if (solve(power) == target) {
                return true;            
            }}
        return false;        
    }
};
