class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        map<int, vector<int>> diag;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                diag[i - j].push_back(mat[i][j]);
            }}
        for (auto& [key, vec] : diag) {
            sort(vec.begin(), vec.end(), greater<int>());  
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mat[i][j] = diag[i - j].back();
                diag[i - j].pop_back();
            }}
        return mat;
    }
};
