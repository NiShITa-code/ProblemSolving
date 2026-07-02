class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        deque<pair<int,int>> dq;

        dist[0][0] = grid[0][0];
        dq.push_front({0,0});   

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        while(!dq.empty()) {
            auto [x,y] = dq.front();
            dq.pop_front();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                    continue;
                }

                int newCost = dist[x][y] + grid[nx][ny];
                
                if(newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    if(grid[nx][ny] == 0)
                        dq.push_front({nx,ny});
                    else
                        dq.push_back({nx,ny});
                }


            }
            

        }
        return dist[n -1][m - 1] < health;

    }
};