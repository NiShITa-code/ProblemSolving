class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        islands = 0
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        visited = [[False] * cols for _ in range(rows)]
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == "1" and not visited[r][c] :
                    islands += 1
                    q = deque([(r, c)])
                    while q:
                        row, col = q.popleft()

                        for dr, dc in directions:
                            nr = row + dr
                            nc = col + dc
                            if (
                                0 <= nr < rows and
                                0 <= nc < cols and
                                grid[nr][nc] == "1" and not visited[nr][nc]

                            ):
                                visited[nr][nc] = True
                                q.append((nr, nc))
        return islands
        
