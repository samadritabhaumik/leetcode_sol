#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<bool> seen;
        for (int i = 0; i<n;++i) {
            seen.assign(n + 1, false); 
            for (int j = 0; j < n; ++j) {
                int v = matrix[i][j];
                if (v < 1 || v > n || seen[v]) return false;
                seen[v] = true;
            }
        }
        for (int j = 0; j < n; ++j) {
            seen.assign(n + 1, false);
            for (int i = 0; i < n; ++i) {
                int v = matrix[i][j];
                if (v<1 || v>n || seen[v]) return false;
                seen[v] = true;
            }}
        return true;
    }
};
