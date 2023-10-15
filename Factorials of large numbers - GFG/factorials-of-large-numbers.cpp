//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
void multiply(vector<int>&arr,int mul,int &sz){
    int carry = 0;
    for(int i=0;i<sz;i++){
        int res = arr[i] * mul;
        res += carry;
        arr[i] = res%10;
        carry = res/10;
        
    }
    while(carry){
        arr[sz] = carry%10;
        sz++;
        carry/=10;
    }
}
    vector<int> factorial(int n){
        // code here
        vector<int>arr(1e5);
        arr[0] = 1;
        int sz = 1;
        for(int i=2;i<=n;i++){
            multiply(arr,i,sz);
        }
        vector<int>ans;
        for(int i = sz-1;i>=0;i--){
            ans.emplace_back(arr[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends