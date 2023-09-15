class Solution {
    int manhattanDistance(vector<int>& point1, vector<int>& point2) {
        return abs(point1[0] - point2[0]) + abs(point1[1] - point2[1]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // edges are manhattan distance
        // its calculating minimum spanning tree in graph
        // 1. Prims's algo
        // grredily hcoose the next min node
        int n = points.size();
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                adj[i].push_back({j, manhattanDistance(points[i], points[j])});
                adj[j].push_back({i, manhattanDistance(points[j], points[i])});
            }

        }
        vector<bool> visited(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> nextMinNode;
        nextMinNode.push({0, 0});
        int cost = 0;
        while (!nextMinNode.empty()) {
            auto next = nextMinNode.top();
            int minDist = next.first;
            int node = next.second;
            nextMinNode.pop();
            if (!visited[node]) {
                visited[node] = true;
                cost += minDist;
                for (auto nbr: adj[node]) {
                    int adjPoint = nbr.first;
                    int edgeWt = nbr.second;
                    if (!visited[adjPoint]) {
                        nextMinNode.push({edgeWt, adjPoint});
                    }
                }
            }

        }
        return cost;


    }
};