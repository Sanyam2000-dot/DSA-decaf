class Solution {
public:
    int climbStairs(int n) {
        unordered_map<int, int> memo;
        return totalWays(0, n, memo );
    }
    int totalWays(int currentStair, int targetStair, unordered_map<int, int> &memo){
        if(currentStair == targetStair){
            return 1;
        }
        if(currentStair >targetStair){
            return 0;
        }
        
        int currentKey = currentStair;
        if(memo.find(currentKey)!= memo.end()){
            return memo[currentKey];
        }
        int oneJump = totalWays(currentStair+1, targetStair, memo);
        int twoJump = totalWays(currentStair+2, targetStair, memo);

        memo[currentKey] = oneJump+twoJump;
        return memo[currentKey];
        
    }
};