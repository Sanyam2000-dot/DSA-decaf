class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
         unordered_map<int, int> memo;
        vector<int> frequency(10001, 0);
        for(int i=0 ; i<nums.size();i++){
            frequency[nums[i]] = frequency[nums[i]] + 1;
        }
        return maxPoint(nums, 0,frequency, memo);
    }
    
    int maxPoint(vector<int> &nums,int currentIndex,vector<int> &frequency , unordered_map<int, int> &memo){
        // vector<int> frequency(10001, 0);
        // for(int i=0 ; i<nums.size();i++){
        //     frequency[nums[i]] = frequency[nums[i]] + 1;
        // }
        
        if(currentIndex >= frequency.size()){
            return  0;
        }
        
        int currentKey = currentIndex;
        if(memo.find(currentKey) != memo.end())
            return memo[currentKey];
        
        int earn = currentIndex * frequency[currentKey] + maxPoint(nums,currentIndex +2,frequency, memo);
        int notEarn = maxPoint(nums, currentIndex + 1, frequency, memo);
        
        memo[currentKey] = max(earn, notEarn);
        
        return memo[currentKey];
    }
};