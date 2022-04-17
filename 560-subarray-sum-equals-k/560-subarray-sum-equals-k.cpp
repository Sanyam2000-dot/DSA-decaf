class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        return totalNumber(nums, k);
    }
    int totalNumber(vector<int> &nums, int k){
        int ans = 0;
        int prefixSum = 0;
        unordered_map<int, int> memo;
        memo[prefixSum] = 1;
        
        for(int i=0;i < nums.size(); i++){
            prefixSum = prefixSum + nums[i];
            
        
            if(memo.find(prefixSum-k) != memo.end()){
                ans = ans + memo[prefixSum-k];
            }
            
            if(memo.find(prefixSum) != memo.end()){
                memo[prefixSum] = memo[prefixSum] +1;
            }
            else{
                memo[prefixSum] = 1;
            }
        }
        return ans;
    }
};