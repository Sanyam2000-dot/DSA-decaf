class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        unordered_map<string, int> memo;
        return totalWays(n, k, target, memo);
    }
    
    int totalWays(int n, int f, int target, unordered_map<string, int> &memo ){
        if(target == 0 && n ==0){
            return 1;
        }
        if(target <= 0 || n==0){
            return 0;
        }
        
        string currentKey = to_string(n) + "- " + to_string(target);
        if(memo.find(currentKey) != memo.end()){
            return memo[currentKey];
        }
        
        int ways= 0;
        int MOD= 1000000007;
        
        for(int i=1;i <=f; i++){
            int tempAns = totalWays(n-1, f, target-i, memo) %MOD;
            ways = ways % MOD;
            ways= (ways+tempAns)%MOD;
        }
        
        memo[currentKey] = ways;
        
        return memo[currentKey];
    }
};