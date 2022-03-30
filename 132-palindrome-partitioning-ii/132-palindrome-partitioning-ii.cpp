class Solution {
public:
    int minCut(string s) {
        // unordered_map<int,int> memo;
        vector<vector<int>> vec(s.size()+1, vector<int> (s.size()+1, -1));
        return minimumCuts(s, 0, s.size()-1, vec);
    }
     bool isPalindrome(string &s, int start, int end){
        while(start<=end){
            if(s.at(start) != s.at(end)){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    int minimumCuts(string &s, int start, int end, vector<vector<int>> &vec){
        if(isPalindrome(s, start, end)){
            return 0;
        }
        
        
        int ans = 1000001;
        
        if(vec[start][end] != -1){
            return vec[start][end];
        }
        // int currentKey = start;
        // if(memo.find(currentKey)!= memo.end()){
        //     return memo[currentKey];
        // }
        for(int i=start; i<end; i++){
           
             if(isPalindrome(s, start, i)){
                 int tempAns = 1+ minimumCuts(s,i+1, end, vec);
                 ans = min(ans, tempAns);
             }
         }
        // memo[currentKey] = ans;
        vec[start][end] = ans;
        
        return vec[start][end];
    }
    
   
};