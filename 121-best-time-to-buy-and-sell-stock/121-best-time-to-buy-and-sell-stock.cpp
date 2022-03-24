class Solution {
public:
    int maxProfit(vector<int>& prices) {
        unordered_map<string, int> memo;
        vector<vector<vector<int>>> mp(prices.size(),vector<vector<int>>(2,vector<int>(2,-1)));
        
        return maxProfits(prices, 0,1, 1, memo, mp);
        
    }
    int maxProfits(vector<int> &prices, int currentDay, int canBuy, int transaction, unordered_map<string, int> &memo,  vector<vector<vector<int>>> &mp ){
        if(currentDay >= prices.size() || transaction ==0)
            return 0;
        
        if(mp[currentDay][canBuy][transaction] != -1)
            return mp[currentDay][canBuy][transaction];
        // string currentKey = to_string(currentDay)+ "-"+ to_string(canBuy) + "-"+ to_string(transaction);
        // if(memo.find(currentKey) != memo.end())
        //     return memo[currentKey];
        int ans =0;
        if(canBuy ==1){
            int idle = maxProfits(prices, currentDay+1, canBuy, transaction , memo, mp);
        int buy = -prices[currentDay] + maxProfits(prices, currentDay+1,0, transaction, memo, mp);
            ans = max(idle, buy);
        }else{
            int idle = maxProfits(prices, currentDay+1, canBuy, transaction, memo, mp );
        int sell = prices[currentDay] + maxProfits(prices, currentDay+1,1, transaction-1, memo, mp);
        ans= max(idle, sell);
        }
        // memo[currentKey] = ans;
        mp[currentDay][canBuy][transaction] = ans;
        return mp[currentDay][canBuy][transaction];
        }
        
};