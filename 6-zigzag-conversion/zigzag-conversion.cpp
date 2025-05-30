class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;
      vector<string> rows(numRows);
        int curr = 0;
        bool down = false;
        for (char c : s) {
            rows[curr] += c;
            if (curr == 0 || curr == numRows - 1) down = !down;
            curr += down ? 1 : -1;}
        string result;
        for (string row : rows) {
            result += row;}
        return result;
    }
};
