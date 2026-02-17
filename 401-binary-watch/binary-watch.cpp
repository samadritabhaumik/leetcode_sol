class Solution {
public:
    int solve(int n) {
        int count = 0;
        while (n > 0) {
            count += (n & 1);   
            n >>= 1;            
        }
        return count;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        for (int HH = 0; HH <= 11; HH++) {
            for (int MM = 0; MM <= 59; MM++) {
                if (solve(HH) + solve(MM) == turnedOn) {
                    string hour = to_string(HH);
                    string minute = (MM < 10 ? "0" : "") + to_string(MM); 
                    result.push_back(hour + ":" + minute);
                }
            }
        }
        return result;
    }
};
