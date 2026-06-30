class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // 边界特判
        if (board.empty() || board[0].empty()) return false;
        if (word.empty()) return true;

        int r = board.size();
        int c = board[0].size();

        // 方向数组
        int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        // 预处理：字符频次剪枝（可选但强烈推荐）
        vector<int> cnt(128, 0);
        for (auto& row : board)
            for (char ch : row) cnt[ch]++;
        for (char ch : word) {
            if (--cnt[ch] < 0) return false;
        }

        // 遍历所有起点
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (dfs(board, dirs, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }

    // word改为const引用，避免拷贝
    bool dfs(vector<vector<char>>& board, int dirs[4][2], const string& word, int i, int j, int index) {
        // 当前字符不匹配直接返回
        if (board[i][j] != word[index])
            return false;
        // 匹配到最后一位，成功
        if (index == word.size() - 1)
            return true;

        char temp = board[i][j];
        board[i][j] = '#'; // 标记已访问

        // 四个方向统一遍历
        int rows = board.size();
        int cols = board[0].size();
        for (int d = 0; d < 4; d++) {
            int ni = i + dirs[d][0];
            int nj = j + dirs[d][1];
            // 边界合法就递归
            if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                if (dfs(board, dirs, word, ni, nj, index + 1)) {
                    return true;
                }
            }
        }

        // 回溯恢复
        board[i][j] = temp;
        return false;
    }
};