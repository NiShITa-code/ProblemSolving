class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) {
            return 0;
        }
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < n; i++) {
            graph[arr[i]].push_back(i);    
        }

        vector<bool>visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int steps = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int node = q.front();
                q.pop();
                if (node == n - 1) {
                    return steps;
                }
                if (node + 1 < n && !visited[node + 1]) {
                    q.push(node + 1);
                    visited[node + 1] = true;
                }
                if (node - 1 >= 0 && !visited[node - 1]) {
                    q.push(node - 1);
                    visited[node - 1] = true;
                }
                for (int nbr: graph[arr[node]]) {
                    if (!visited[nbr]) {
                        visited[nbr] = true;
                        q.push(nbr);
                    }
                }
                graph[arr[node]].clear();
            }
            steps++;
        }
        return 0;
    }
};