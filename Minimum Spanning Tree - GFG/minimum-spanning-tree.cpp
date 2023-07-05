//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    public:
    vector <int> parent, size;
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int findParent(int num) {
        if (parent[num] == num) {
            return num;
        }
        return parent[num] = findParent(parent[num]);
    }
    
    void unionBySize(int u, int v) {
        int ultimate_parent_u = findParent(u);
        int ultimate_parent_v = findParent(v);
        if (ultimate_parent_u == ultimate_parent_v) {
            return;
        }
        if (size[ultimate_parent_u] < size[ultimate_parent_v]) {
            parent[ultimate_parent_u] = ultimate_parent_v;
            size[ultimate_parent_v] += size[ultimate_parent_u];
        } else {
            parent[ultimate_parent_v] = ultimate_parent_u;
            size[ultimate_parent_u] += size[ultimate_parent_v];
        }
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        // weight, {u, v}
        vector<pair<int, pair<int, int>>> edges;
        for (int node = 0; node < V; node++) {
            for (auto nbr: adj[node]) {
                int adjNode = nbr[0];
                int wt = nbr[1];
                edges.push_back({wt, {node, adjNode}});
            }
        }
        // sorting the edges on the bases of weight
        sort(edges.begin(), edges.end());
        DisjointSet ds(V);
        int mstWeight = 0;
        for (auto edge : edges) {
            int wt = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;
            
            if (ds.findParent(u) != ds.findParent(v)) {
                mstWeight += wt;
                ds.unionBySize(u, v);
            }
        }
        
        return mstWeight;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends