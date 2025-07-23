class Solution {
public:
    int maximumGain(string s, int x, int y) {
         int n=s.length();
        int score=0;
        string maxi = (x>y)?"ab":"ba";
        string mini = (maxi == "ab") ? "ba" : "ab"; 
        string temp_first= solve(s, maxi);
        int rem=(n - temp_first.length()) / 2;
        score+= rem * max(x, y);
        string temp_second = solve(temp_first, mini);
        rem  = (temp_first.length() - temp_second.length()) / 2;
        score+= rem * min(x, y);
        return score;
    }
private:
    string solve(string& s, string& matchStr) {
        stack<char> st;
        for (char &ch : s) {
            if (ch == matchStr[1] && !st.empty() && st.top() == matchStr[0]) {
                st.pop();
            } else {
                st.push(ch);
            }}
        string rem;
        while (!st.empty()) {
            rem.push_back(st.top());
            st.pop();
        }
        reverse(rem.begin(), rem.end());
        return rem;
    }
};

