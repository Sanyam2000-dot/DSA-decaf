// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        unordered_map<string, int> memo;
        return maxProfit(price, 0, n, memo);
    }
    int maxProfit(int price[], int currentIndex, int n, unordered_map<string, int> &memo){
        if(n==0)
        return 0;
        if(currentIndex >= n)
        return 0;
        string currentKey = to_string(currentIndex) + "-" + to_string(n);
        if(memo.find(currentKey) != memo.end())
        return memo[currentKey];
        int consider = 0;
        int currentPieceLength = currentIndex+1;
        if(currentPieceLength <= n)
        consider = price[currentIndex]+maxProfit(price, currentIndex, n-currentPieceLength, memo);
        
        int notConsider= maxProfit(price, currentIndex+1, n, memo);
        memo[currentKey] = max(consider, notConsider);
        return memo[currentKey];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends