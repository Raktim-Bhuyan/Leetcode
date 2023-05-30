//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
 
    
    bool dfs(int r, int c, int idx, vector<vector<char>>& board, string &word, int &m, int &n) {
        if(idx == word.size()) return 1;
        int x[] = {1,-1,0,0};
        int y[] = {0,0,1,-1};
        char ch = board[r][c];
        board[r][c] = '0';
        bool res = 0;
        for(int k = 0; k < 4; k++) {
            int nr = r + x[k];
            int nc = c + y[k];
            
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && 
               board[nr][nc] != '0' && board[nr][nc] == word[idx]) {
                   
                res |= dfs(nr, nc, idx + 1, board, word, m, n);
                
            }
        }
        board[r][c] = ch;
        return res;
    }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(i, j, 1, board, word, m, n)) return 1;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends