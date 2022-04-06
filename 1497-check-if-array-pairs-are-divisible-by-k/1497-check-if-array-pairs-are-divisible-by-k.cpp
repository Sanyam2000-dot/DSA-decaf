class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
        
        vector<int> mp(k,0);
        return checkPair(arr, k, mp );
    }
    
    bool checkPair(vector<int>&arr , int k, vector<int> &mp){
        for(auto currentVal: arr){
            int currentRem = ((currentVal%k)+k)%k;
            mp[currentRem] += 1;
        }
        
        for(int i=0; i<=k/2; i++){
            if(i==0){
                if(mp[i]%2 !=0)
                    return false;
            }
            else{
                int y = k-i;
                if(mp[i] != mp[y]){
                    return false;
                }
            }
        }
        return true;
        
    }
};