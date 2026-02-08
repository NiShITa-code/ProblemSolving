class Solution {
public:
    void bfs(int row, int col, vector<vector<bool>>& vis, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = true;  // mark visited when pushed
        
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (auto& d : dir) {
                int nr = r + d.first;
                int nc = c + d.second;
                
                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    grid[nr][nc] == '1' &&
                    !vis[nr][nc]) {
                    
                    vis[nr][nc] = true;   // mark before pushing
                    q.push({nr, nc});
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int totalIsland = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    bfs(i, j, visited, grid);
                    totalIsland++;
                }
            }
        }
        return totalIsland;
    }
};
