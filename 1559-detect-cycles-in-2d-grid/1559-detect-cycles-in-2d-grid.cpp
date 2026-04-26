#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        for (int sr = 0; sr < m; sr++) {
            for (int sc = 0; sc < n; sc++) {
                if (visited[sr][sc])
                    continue;

                queue<array<int, 4>> q;
                q.push({sr, sc, -1, -1});
                visited[sr][sc] = true;

                while (!q.empty()) {
                    auto [r, c, parentR, parentC] = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nr = r + dr[k];
                        int nc = c + dc[k];

                        if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                            continue;

                        if (grid[nr][nc] != grid[r][c])
                            continue;

                        if (nr == parentR && nc == parentC)
                            continue;

                        if (visited[nr][nc])
                            return true;

                        visited[nr][nc] = true;
                        q.push({nr, nc, r, c});
                    }
                }
            }
        }

        return false;
    }
};