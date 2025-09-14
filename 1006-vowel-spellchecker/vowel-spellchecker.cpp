class Solution {
    unordered_set<string> words;
    unordered_map<string, string> cap;
    unordered_map<string, string> vow;

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        words.clear();
        cap.clear();
        vow.clear();

        for (string word : wordlist) {
            words.insert(word);

            string wordlow = toLower(word);
            if (!cap.count(wordlow))
                cap[wordlow] = word;
            string wordlowDV = devowel(wordlow);
            if (!vow.count(wordlowDV))
                vow[wordlowDV] = word;
        }
        vector<string> ans;
        for (string query : queries) {
            ans.push_back(solve(query));
        }
        return ans;
    }
private:
    string solve(string query) {
        if (words.count(query))
            return query;
        string queryL = toLower(query);
        if (cap.count(queryL))
            return cap[queryL];
        string queryLV = devowel(queryL);
        if (vow.count(queryLV))
            return vow[queryLV];
        return "";
    }
    string devowel(const string& word) {
        string ans;
        for (char c : word) {
            if (isVowel(c)) ans.push_back('*');
            else ans.push_back(c);
        }
        return ans;
    }
    string toLower(string s) {
        for (char& c : s) 
        c=tolower(c);
        return s;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
