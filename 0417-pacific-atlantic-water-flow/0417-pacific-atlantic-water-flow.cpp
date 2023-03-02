class Solution {

private:
    void bfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, queue<pair<int, int>>& q) {
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int m = matrix.size();
        int n = matrix[0].size();
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;
            for (vector<int>& dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                    continue;
                }
                if (!visited[nx][ny] && matrix[nx][ny] >= matrix[x][y]) {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        int m = matrix.size();
        if (m == 0) return res;
        int n = matrix[0].size();
        vector<vector<bool>> p(m, vector<bool>(n, false));
        vector<vector<bool>> a(m, vector<bool>(n, false));
        queue<pair<int, int>> pq, aq;
        for (int i = 0; i < m; i++) {
            pq.push(make_pair(i, 0));
            aq.push(make_pair(i, n-1));
            p[i][0] = true;
            a[i][n-1] = true;
        }
        for (int j = 0; j < n; j++) {
            pq.push(make_pair(0, j));
            aq.push(make_pair(m-1, j));
            p[0][j] = true;
            a[m-1][j] = true;
        }
        bfs(matrix, p, pq);
        bfs(matrix, a, aq);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (p[i][j] && a[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
