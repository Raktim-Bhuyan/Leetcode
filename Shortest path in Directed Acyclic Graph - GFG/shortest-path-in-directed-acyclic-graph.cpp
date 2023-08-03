//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define pr pair<int,int>
class Solution {
  public:
  //dijkstra algorithm
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<int>dis(N,1e9);
        dis[0] = 0;
        vector<pair<int,int>>adj[N];
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int d = it[2];
            adj[u].push_back({d,v});
        }
        priority_queue<pr,vector<pr>,greater<pr>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int currdis = it.first;
            for(auto it:adj[node]){
                int w = it.first;
                int e = it.second;
                if(dis[e] > currdis + w){
                    dis[e] = currdis + w;
                    pq.push({dis[e],e});
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dis[i] == 1e9){
                dis[i] = -1;
            }
        }
        return dis;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends