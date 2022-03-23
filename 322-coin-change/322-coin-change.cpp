class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<string, int> memo;
       vector<vector<int>> mp(coins.size()+1, vector<int>(amount+1, -1));
        int ans=  minWays(coins, 0, amount, memo, mp);
        
        if(ans == 10001)
            return -1;
        return ans;
    }
    int minWays(vector<int>&coins, int currentCoin, int amount, unordered_map<string, int> &memo, vector<vector<int>>&mp){
        if(amount == 0)
            return 0;
        if(currentCoin>= coins.size())
            return 10001;
        
        // string currentKey = to_string(currentCoin) + "-" + to_string(amount);
        // if(memo.find(currentKey) != memo.end()){
        //     return memo[currentKey];
        
        if(mp[currentCoin][amount] != -1)
            return mp[currentCoin][amount];
        
        
        int  currentCoinValue = coins[currentCoin];
        
        int consider = 10001;
        
        if(currentCoinValue <= amount){
            consider = 1 + minWays(coins, currentCoin, amount- currentCoinValue, memo, mp);
        }
        int notConsider = minWays(coins, currentCoin+1, amount, memo, mp);
        // memo[currentKey] = min(consider, notConsider);
    
    mp[currentCoin][amount] = min(consider, notConsider);
        return mp[currentCoin][amount];
    }
};