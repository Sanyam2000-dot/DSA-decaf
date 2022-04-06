class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, bool> memo1;
        
        return common(nums1, nums2, memo1);
    }
    
    vector<int> common(vector<int>& nums1, vector<int>& nums2, unordered_map<int, bool> &memo1){
        
        for(auto i:nums1){
            
                memo1[i] =   true;
            
        }
        vector<int> ans;
        
    for(auto i:nums2){
            if(memo1.find(i) != memo1.end() && memo1[i]==true ){
                ans.push_back(i);
                memo1[i] = false;
            }
        }
        return ans;
    }
        
};