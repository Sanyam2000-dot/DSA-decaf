class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        unordered_map<string, int> memo;
        return totalWays(0, 0, obstacleGrid.size(), obstacleGrid[0].size(), memo, obstacleGrid);
    }
 int totalWays(int currentRow, int currentCol, int m, int n, unordered_map<string, int> &memo, vector<vector<int>>& obstacleGrid){
     
      if(currentRow>=m || currentCol>=n || obstacleGrid[currentRow][currentCol] ==1){
            return 0;
        }
        
        if(currentRow == m-1 && currentCol == n-1){
            return 1;
        }
       
        string currentKey = to_string(currentRow)+"-"+to_string(currentCol);
        
        if(memo.find(currentKey)!= memo.end()){
            return memo[currentKey];
        }
        int rightMove = totalWays(currentRow, currentCol+1, m, n, memo,  obstacleGrid);
        int downMove = totalWays(currentRow+1, currentCol, m, n, memo,  obstacleGrid);
        
        
        memo[currentKey] = rightMove + downMove ;
        return memo[currentKey] ;
    }
};