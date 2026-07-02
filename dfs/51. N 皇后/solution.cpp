#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        // 初始化n*n棋盘，全部填充空位'.'
        vector<string> board(n, string(n, '.'));
        // 三个集合：已占用列、主对角线(行-列)、副对角线(行+列)
        unordered_set<int> col_set, diag1_set, diag2_set;
        // 从第0行开始深度优先搜索
        dfs(res, board, 0, col_set, diag1_set, diag2_set, n);
        return res;
    }

    /**
     * @param res 存放所有合法方案
     * @param board 当前棋盘布局
     * @param row 当前正在放置皇后的行数
     * @param col_set 已经放过皇后的列
     * @param diag1_set 主对角线：row-col 相同的位置会互相攻击
     * @param diag2_set 副对角线：row+col 相同的位置会互相攻击
     * @param n 棋盘大小
     */
    void dfs(vector<vector<string>>& res, vector<string>& board, int row,
             unordered_set<int>& col_set, unordered_set<int>& diag1_set,
             unordered_set<int>& diag2_set, int n)
    {
        // 递归终止：所有行都放置完皇后，得到一组合法解
        if (row == n)
        {
            res.push_back(board);
            return;
        }
        // 遍历当前行每一列，尝试放置皇后
        for (int col = 0; col < n; col++)
        {
            int diag1 = row - col;
            int diag2 = row + col;
            // 当前列、两条对角线都没有皇后，才可以放置
            if (!col_set.count(col) && !diag1_set.count(diag1) && !diag2_set.count(diag2))
            {
                // 放置皇后
                board[row][col] = 'Q';
                // 标记该列、两条对角线已被占用
                col_set.insert(col);
                diag1_set.insert(diag1);
                diag2_set.insert(diag2);

                // 递归处理下一行
                dfs(res, board, row + 1, col_set, diag1_set, diag2_set, n);

                // 回溯：撤销本次放置，恢复棋盘和标记集合
                board[row][col] = '.';
                col_set.erase(col);
                diag1_set.erase(diag1);
                diag2_set.erase(diag2);
            }
        }
    }
};