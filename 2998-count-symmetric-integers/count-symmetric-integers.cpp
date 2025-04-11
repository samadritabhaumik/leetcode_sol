class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; i++) {
            std::string num = std::to_string(i);
            int len = num.size();
            if (len % 2 == 0) {
                int half = len / 2;
                int sumFirstHalf = 0, sumSecondHalf = 0;
             for (int j = 0; j < half; j++) {
                    sumFirstHalf += num[j] - '0';
                    sumSecondHalf += num[half + j] - '0';
                }
                if (sumFirstHalf == sumSecondHalf) {
                count++;
            }}}
        return count; 
    }
};