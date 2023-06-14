//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        // for shortest path we are going to maintain the track of the parent
        vector<pair<int, int>> adj[n+1];
        for (auto edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n+1, INT_MAX);
        dist[1] = 0;
        vector<int> parent(n+1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        pq.push({0, 1});
        while(!pq.empty()) {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for (auto nbr: adj[node]) {
                int adjNode = nbr.first;
                int edgeWeight = nbr.second;
                if (dis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWeight;
                    parent[adjNode] = node;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        if (dist[n] == INT_MAX) return {-1};
        vector<int> ans;
        int node = n;
        while(parent[node] != node) {
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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