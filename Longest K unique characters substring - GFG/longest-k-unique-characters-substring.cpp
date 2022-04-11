// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
     return longestSub(s, k);
    }
    
    int longestSub(string &s, int k){
        unordered_map<char, int> memo;
        int distinct =0;
        int release = 0;
        int ans =0;
        for(int aquire = 0; aquire<s.size(); aquire++){
            char currentChar = s.at(aquire);
            if(memo.find(currentChar) != memo.end()){
                memo[currentChar] = memo[currentChar] +1;
            }else{
                memo[currentChar] = 1;
                distinct += 1;
            }

            while(release <= aquire && distinct > k){
                char disChar = s.at(release);
                memo[disChar]  = memo[disChar] -1;
                release += 1;
                if(memo[disChar] == 0 ){
                memo.erase(disChar);
                distinct -= 1;}
            }
            if(distinct == k){
            ans = max(ans, aquire - release +1);}
        }
        
        return ans== 0 ? -1 : ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends