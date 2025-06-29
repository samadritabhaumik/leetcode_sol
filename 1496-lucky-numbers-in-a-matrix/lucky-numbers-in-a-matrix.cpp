class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(),n=matrix[0].size();
        vector<int> row(m, INT_MAX);
        vector<int> col(n, INT_MIN);
                vector<int> res;
        for (int i=0;i<m;++i)
            for (int j=0;j<n;++j)
                row[i]=min(row[i], matrix[i][j]);
        for (int j=0;j<n;++j)
            for (int i=0;i<m;++i)
                col[j] = max(col[j], matrix[i][j]);
        for (int i=0;i<m;++i)
            for (int j=0;j<n;++j)
                if (matrix[i][j] == row[i] && matrix[i][j] == col[j])
                    res.push_back(matrix[i][j]);
        return res;
    }
};
