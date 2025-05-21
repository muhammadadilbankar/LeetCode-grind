class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int, int>> pos;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0)
                pos.push_back({i, j});
            }
        }
        for(auto p : pos){
            int y = p.first;
            int x = p.second;
            for (int col = 0; col < n; col++) matrix[y][col] = 0; // zero row y
            for (int row = 0; row < m; row++) matrix[row][x] = 0; // zero column x
        }
        return;
    }
};