class Solution {
public:
   
// T.C. O(n^2), S.C. O(n^2) [not inplace]
vector<vector<int>> transpose(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    // n x m matrix for transpose
    vector<vector<int>> trans(n, vector<int>(m, 0));

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            trans[j][i] = matrix[i][j];

    return trans;
}
};