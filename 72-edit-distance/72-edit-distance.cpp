class Solution {
public:
    int minDistance(string s1, string s2) {
    vector<vector<int>> mp(501, vector<int> (501, -1));
        return minOps(s1, s2, 0, 0, s1.size(), s2.size(), mp);
        
    }
    
    int minOps(string &s1, string &s2, int i, int j, int m, int n, vector<vector<int>> &mp ){
        if(i>=m){
            return n-j;
        }
        if(j>=n){
            return m-i;
            }
        
        if(mp[i][j] != -1){
            return mp[i][j];
        }
        
        int ans =1000001;
        if(s1.at(i) == s2.at(j)){
            ans = minOps(s1, s2, i+1, j+1, m, n, mp);
        }else{
            int insert = 1 + minOps(s1, s2, i, j+1, m, n, mp);
            int deletOp = 1 + minOps(s1, s2, i+1, j, m, n, mp);
            int replace = 1 + minOps(s1, s2, i+1, j+1, m, n, mp);
            ans = min(insert, min(deletOp, replace));
        }
        
        mp[i][j] = ans;
        
        return mp[i][j];
            
        
    }
};