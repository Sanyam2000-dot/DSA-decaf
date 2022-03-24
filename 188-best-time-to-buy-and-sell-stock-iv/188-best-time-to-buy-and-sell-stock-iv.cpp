class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        unordered_map<string, int> memo;
        vector<vector<vector<int>>> mp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        
        return maxProfits(prices, 0,1, k, memo, mp);
    }
    int maxProfits(vector<int> &prices, int currentDay, int canBuy, int k, unordered_map<string, int> &memo,  vector<vector<vector<int>>> &mp ){
        if(currentDay >= prices.size() || k ==0)
            return 0;
        
        if(mp[currentDay][canBuy][k] != -1)
            return mp[currentDay][canBuy][k];
        // string currentKey = to_string(currentDay)+ "-"+ to_string(canBuy) + "-"+ to_string(transaction);
        // if(memo.find(currentKey) != memo.end())
        //     return memo[currentKey];
        int ans =0;
        if(canBuy ==1){
            int idle = maxProfits(prices, currentDay+1, canBuy, k, memo, mp);
        int buy = -prices[currentDay] + maxProfits(prices, currentDay+1,0, k, memo, mp);
            ans = max(idle, buy);
        }else{
            int idle = maxProfits(prices, currentDay+1, canBuy, k, memo, mp );
        int sell = prices[currentDay] + maxProfits(prices, currentDay+1,1, k-1, memo, mp);
        ans= max(idle, sell);
        }
        // memo[currentKey] = ans;
        mp[currentDay][canBuy][k] = ans;
        return mp[currentDay][canBuy][k];
        }
        
};