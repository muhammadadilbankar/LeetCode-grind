class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(auto row : board){
            vector<int> rowHash(10, 0);
            for(int i=0; i<9; i++){
                if(row[i] != '.')
                rowHash[row[i] - '0']++;
            }
            for(auto e : rowHash){
                if(e > 1) {
                    cout << "false due to column checking" << endl;
                    return false;
            }
            }
        }
        for(int i=0; i<9; i++){
            vector<int> colHash(10, 0);
            for(int j=0; j<9; j++){
                if(board[j][i] != '.')
                colHash[board[j][i] - '0']++;
            }
            for(auto e : colHash){
                if(e > 1) {
                    cout << "false due to column checking" << endl;
                    return false;
            }
        }
        }
    for(int rowStart = 0; rowStart < 9; rowStart += 3){
      for(int colStart = 0; colStart < 9; colStart += 3){
        vector<int> gridHash(10, 0);
        for(int i = rowStart; i < rowStart + 3; i++){
            for(int j = colStart; j < colStart + 3; j++){
                if(board[i][j] != '.')
                    gridHash[board[i][j] - '0']++;
            }
        }
        for(auto e : gridHash){
            if(e > 1){
                cout << "false due to grid checking at starting position (" 
                     << rowStart << "," << colStart << ")" << endl;
                return false;
            }
        }
    }
}
        return true;
    }
};