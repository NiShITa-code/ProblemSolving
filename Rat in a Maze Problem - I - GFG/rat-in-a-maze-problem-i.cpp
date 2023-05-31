//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    //
    void solve(int i, int j, vector<vector<int>> &m, vector<vector<int>>&visited, vector<string>& ans, string moves, int n) {
        // rat can go in 4 directions
        if (i == n - 1 && j == n-1) {
            ans.push_back(moves);
            return;
        }
        string dir = "DLRU";
        int di[4] = {1,0, 0, -1};
        int dj[4] = {0,-1, 1, 0};
        
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (ni >= 0 && nj >= 0 && ni < n && nj < n && !visited[ni][nj] && m[ni][nj] == 1) {
                visited[i][j] = 1;
                solve(ni, nj, m, visited, ans, moves+dir[k], n);
                visited[i][j] = 0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        string moves;
        if (m[0][0] == 1) {
            solve(0, 0, m, visited, ans, moves, n);    
        }
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends