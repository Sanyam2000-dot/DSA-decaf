// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
class Solution{
  public:
    int maxLen(int arr[], int N)
    {
        unordered_map<int, int> memo;
        return lenLargest(arr, N, memo);
    }
    int lenLargest(int A[], int n, unordered_map<int, int>& memo){
        int prefixSum = 0;
        int ans = 0;
        
        memo[prefixSum] = -1;
        
        
         for(int i =0;i < n; i++){
              if(A[i] == 0){
                A[i]= -1;
            }
            else{
                A[i]= 1 ;
            }
         }
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
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.maxLen(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends