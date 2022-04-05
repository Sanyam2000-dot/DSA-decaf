class Solution {
public:
    int rob(vector<int>& nums) {
        unordered_map<int, int> memo;
        return maxMoney(0, nums, memo);
    }
    
    int maxMoney(int currentHouse, vector<int> &nums, unordered_map<int, int> &memo){
        if(currentHouse >=  nums.size()){
            return 0;
        }
        
        int currentKey = currentHouse;
        if(memo.find(currentKey) != memo.end()){
            return memo[currentKey];
        }
        
        int currentMoney = nums[currentHouse];
        int notRob = maxMoney(currentHouse+1, nums, memo );
        int Rob =currentMoney + maxMoney(currentHouse+2, nums, memo );
        
        
        memo[currentKey] = max(Rob, notRob);
        
        return memo[currentKey];

        
    }
};