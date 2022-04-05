class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int, int> memo;
        return min(minCost(1,cost, memo), minCost(0, cost, memo));
    }
    
    int minCost(int currentStair, vector<int> &cost, unordered_map<int,int> &memo){
        if(currentStair == cost.size()){
            return 0;
        }
        if(currentStair>cost.size()){
            return 1000;
        }
        
        int currentCost = cost[currentStair];
        int currentKey = currentStair;
        
        if(memo.find(currentKey) != memo.end()){
            return memo[currentKey];
        }
        int oneJump = currentCost + minCost(currentStair+1, cost, memo);
        int twoJump = currentCost + minCost(currentStair+2, cost, memo);
        
        memo[currentKey] = min(oneJump, twoJump);
        
        return memo[currentKey];

        
    }
};