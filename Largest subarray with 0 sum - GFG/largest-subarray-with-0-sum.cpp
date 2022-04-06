// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   unordered_map<int, int> memo;
        return lenLargest(A, n, memo);
    }
    
    int lenLargest(vector<int>&A, int n, unordered_map<int, int> &memo){
        int prefixSum = 0;
        int ans = 0;
        
        memo[prefixSum] = -1;
        for(int i =0;i < n; i++){
            prefixSum = prefixSum + A[i];
            
            if(memo.find(prefixSum)!=memo.end()){
                ans = max(ans, i-memo[prefixSum]);
            }else{
                memo[prefixSum] = i;
            }
        }
        
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends