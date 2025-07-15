class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) {
            return false;
        }
        bool vowel=false,cons=false;
        for (auto c:word) {
            if (isalpha(c)) {
                c=tolower(c);
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    vowel=true;
                } else {
                    cons=true;
                }
            } else if(!isdigit(c)) {
                return false;
            }
        }
        return vowel && cons;
    }
};