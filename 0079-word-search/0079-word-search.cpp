class Solution {
private:
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int i, int j, int idx) {
        if (idx == word.size()) {
            return true;
        }
        
        int m = board.size();
        int n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || board[i][j] != word[idx]) {
            return false;
        }
        
        visited[i][j] = true; // mark cell as visited
        bool found = dfs(board, visited, word, i+1, j, idx+1) ||
                     dfs(board, visited, word, i-1, j, idx+1) ||
                     dfs(board, visited, word, i, j+1, idx+1) ||
                     dfs(board, visited, word, i, j-1, idx+1); // check adjacent cells
        visited[i][j] = false; // unmark cell as visited
        
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false)); // to keep track of visited cells
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0] && dfs(board, visited, word, i, j, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};