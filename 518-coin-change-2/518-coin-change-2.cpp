class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // unordered_map<string, int> memo;
       vector<vector<int>> mp(coins.size()+1, vector<int>(amount+1, -1));
        return totalWays(coins, 0, amount, mp);
    }
    
    int totalWays(vector<int> &coins, int currentCoin, int amount,vector<vector<int>>&mp){
        if(amount == 0){
            return 1;
        }
        if(currentCoin  >= coins.size()){
            return 0;
        }
        
        // string currentKey = to_string(currentCoin) + "-" + to_string(amount);
        
        // if(memo.find(currentKey) != memo.end()){
        //     return memo[currentKey];
        // }
        
        if(mp[currentCoin][amount] !=-1){
            return mp[currentCoin][amount];
        }
            
            int currentCoinValue = coins[currentCoin];
            int consider= 0;
    if(currentCoinValue<= amount){
        consider = totalWays(coins, currentCoin, amount - currentCoinValue, mp);
    }
        int notConsider = totalWays(coins, currentCoin+1, amount, mp);
        // memo[currentKey] = consider+ notConsider;
        mp[currentCoin][amount] = consider+ notConsider;
        return  consider+ notConsider;
    }
};