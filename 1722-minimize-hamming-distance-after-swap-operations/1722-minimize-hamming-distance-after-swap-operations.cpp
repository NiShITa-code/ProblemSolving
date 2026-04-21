class Solution {
public:
    class DSU {
        public:
        vector<int> parent, rankv;

        DSU(int n) {
            parent.resize(n);
            rankv.resize(n, 0);

            // Initially every node is its own parent
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        } 

        // Find the root (representative) of x
        int find(int x) {
            // Path compression:
            // make every visited node directly point to root
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        // Merge the sets containing x and y
        void unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            // already in same component
            if (rootX == rootY) return;

            // Union by rank: attach smaller tree under bigger tree
            if (rankv[rootX] < rankv[rootY]) {
                parent[rootX] = rootY;
            } else if (rankv[rootX] > rankv[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rankv[rootX]++;
            }
        }


    };
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
         int n = source.size();

        // Step 1: Build connected components using DSU
        DSU dsu(n);

        for (auto &edge : allowedSwaps) {
            int a = edge[0];
            int b = edge[1];
            dsu.unite(a, b);
        }

        // Step 2: Group indices by their component root
        unordered_map<int, vector<int>> groups;

        for (int i = 0; i < n; i++) {
            int root = dsu.find(i);
            groups[root].push_back(i);
        }

        int answer = 0;

        // Step 3: For each connected component
        for (auto &entry : groups) {
            vector<int> &indices = entry.second;

            // Count frequency of values present in source inside this component
            unordered_map<int, int> freq;
            for (int idx : indices) {
                freq[source[idx]]++;
            }

            // Try to match target values using available source values
            for (int idx : indices) {
                if (freq[target[idx]] > 0) {
                    // match found, use one occurrence
                    freq[target[idx]]--;
                } else {
                    // no matching value available in this component
                    // so this position must remain mismatched
                    answer++;
                }
            }
        }

        return answer;
        
    }
};