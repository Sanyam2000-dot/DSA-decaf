class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> mp(1001, vector<int>(1001, -1));
        return lengthOfLCS(text1, text2, 0, 0, text1.size(), text2.size(), mp);
    }
    int lengthOfLCS(string &s1, string &s2, int i, int j, int m, int n, vector<vector<int>> &mp){
        if(i>=m || j>=n){
            return 0;
        }
        
        int ans= 0;
        
        if(mp[i][j] != -1){
            return mp[i][j];
        }
        
        if(s1.at(i) == s2.at(j)){
             ans = 1+ lengthOfLCS(s1, s2, i+1, j+1, m, n,mp);
        }else{
            int a = lengthOfLCS(s1, s2, i, j+1, m, n, mp);
            int b = lengthOfLCS(s1, s2, i+1, j, m, n, mp);
            ans = max(a, b);
        }
        
        mp[i][j] = ans;
        
        return mp[i][j];
    }
};