/* Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify the height of each tower either by increasing or decreasing them by K only once. After modifying, height should be a non-negative integer. 
Find out the minimum possible difference of the height of shortest and longest towers after you have modified each tower.

You can find a slight modification of the problem here.
Note: It is compulsory to increase or decrease by K to each tower.*/



// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


class Solution {
 public:
  int getMinDiff(int arr[], int n, int k) {
      // code here
      sort(arr,arr+n);  
      int maxie,minie;
      int ans = arr[n-1] - arr[0];
       
      for(int i=1;i<n;i++){
       
          if(arr[i]>=k){
              maxie = max(arr[i-1]+k,arr[n-1]-k);
              minie = min(arr[0]+k,arr[i]-k);
              ans = min(ans,maxie-minie);
          }    
           
      }
  return ans; 
       
  }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;a
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
