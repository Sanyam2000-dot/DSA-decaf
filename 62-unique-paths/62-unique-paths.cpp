class Solution {
public:
    int uniquePaths(int m, int n) {
        unordered_map<string, int> memo;
        return totalWays(0, 0, m, n, memo);
        
    }
    int totalWays(int currentRow, int currentCol, int m, int n, unordered_map<string, int> &memo){
        if(currentRow == m-1 && currentCol == n-1){
            return 1;
        }
        if(currentRow>=m || currentCol>=n){
            return 0;
        }
        
        string currentKey = to_string(currentRow)+"-"+to_string(currentCol);
        
        if(memo.find(currentKey)!= memo.end()){
            return memo[currentKey];
        }
        int rightMove = totalWays(currentRow, currentCol+1, m, n, memo);
        int downMove = totalWays(currentRow+1, currentCol, m, n, memo);
        
        
        memo[currentKey] = rightMove + downMove ;
        return memo[currentKey] ;
    }
};