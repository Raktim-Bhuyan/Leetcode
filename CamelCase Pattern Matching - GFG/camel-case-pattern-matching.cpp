//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> d, string pattern) {
        // code here
        int n = pattern.size();
        map<string,vector<string>>mp;
        for(int i=0;i<d.size();i++){
            string s = d[i];
            string t = "";
            for(auto it:s){
                if(it>=65 and it<=90){
                    t.push_back(it);
                }
            }
            mp[t].push_back(s);
        }
        vector<string>ans;
        for(auto it:mp){
            string b = it.first;
            if(b.size()>n)
            b = b.substr(0,n);
            if(b == pattern){
                for(auto x: it.second){
                    ans.push_back(x);
                }
            }
        }
        if(ans.size()==0)return {"-1"};
        sort(ans.begin(),ans.end());
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
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends