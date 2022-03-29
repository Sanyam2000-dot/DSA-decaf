class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 100001;
        unordered_map<string, int> memo;
        for(int currentCol = 0; currentCol < n; currentCol ++){
            int tempAns = minPathSum(matrix, 0, currentCol, m, n, memo);
            ans = min(tempAns, ans);
        }
        
        return ans;
    }
    int minPathSum(vector<vector<int>>& matrix, int currentRow, int currentCol, int m, int n, unordered_map<string, int> &memo){
        if(currentCol<0 || currentCol>=n){
            return 100001;
        }
        
        if(currentRow == m-1){
            return matrix[currentRow][currentCol];
        }
        string currentKey = to_string(currentRow) + "-" + to_string(currentCol);
        if(memo.find(currentKey) != memo.end()){
            return memo[currentKey];
        }
        int leftDiag =  matrix[currentRow][currentCol]+minPathSum(matrix, currentRow+1, currentCol-1, m, n, memo);
        int down = matrix[currentRow][currentCol]+ minPathSum(matrix, currentRow+1, currentCol, m, n, memo);
        int rightDiag = matrix[currentRow][currentCol]+  minPathSum(matrix, currentRow+1, currentCol+1, m, n, memo);

        memo[currentKey] = min(leftDiag, min(down, rightDiag));
        return memo[currentKey];
    }
};