class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         // unordered_map<char, int> memo;
        return countUniq(s);
    }
    int countUniq(string s){
        unordered_map<char, int> memo;
        int ans =0;
        int release = 0;
        
        for(int aquire= 0;aquire<s.size(); aquire++){
            char currentChar = s.at(aquire);
            
            while(release < aquire && memo.find(currentChar) != memo.end()){
                char disChar = s.at(release);
                memo.erase(disChar);
                release = release+1;
            }
            
            memo[currentChar] = aquire;
            ans = max(ans,aquire-release+1);
        }
        
        return ans;
    }
};