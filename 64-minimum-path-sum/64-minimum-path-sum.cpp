class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        unordered_map<string, int> memo;
      return minCost(0,0, grid.size(), grid[0].size(), grid, memo);  
    }
    
    int minCost(int currentRow, int currentCol, int m, int n, vector<vector<int>>& grid,unordered_map<string, int> & memo){
        if(currentRow == m-1 && currentCol == n-1){
            return grid[currentRow][currentCol];
        }
        
        if(currentRow >=m || currentCol >=n){
            return 100001;
        }
        
        string currentKey = to_string(currentRow)+"-"+to_string(currentCol);
        
        if(memo.find(currentKey)!= memo.end()){
            return memo[currentKey];
        }
        int rightMove = grid[currentRow][currentCol]+minCost(currentRow, currentCol+1, m, n,grid, memo);
        int downMove = grid[currentRow][currentCol]+minCost(currentRow+1, currentCol, m, n,grid, memo);
        
        
        memo[currentKey] = min(rightMove , downMove) ;
        return memo[currentKey] ;
        
    }
};