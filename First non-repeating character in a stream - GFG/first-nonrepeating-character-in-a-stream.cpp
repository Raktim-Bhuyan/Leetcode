//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		   string ans = "";
		   queue<char>q;
		   vector<int>freq(26,0);
		   for(int i=0;i<A.size();i++){
		       freq[A[i]-'a']++;
		       if(freq[A[i]-'a'] ==1){
		           q.push(A[i]);
		       }
		       while(q.size() and freq[q.front()-'a'] !=1){
		           q.pop();
		       }
		       if(q.size()){
		           ans.push_back(q.front());
		       }
		       else{
		           ans.push_back('#');
		       }
		   }
		   return ans;
		    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends