class Solution {
public:
    // 四个方向：上、下、左、右
    const int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    // dfs参数：当前位置(i,j)、上一步的位置(pi,pj)、网格、访问标记、当前字符
    bool dfs(int i, int j, int pi, int pj, vector<vector<char>>& grid, vector<vector<bool>>& vis, char c) {
        // 1. 越界检查
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return false;
        // 2. 字符不同，走不通
        if (grid[i][j] != c) return false;
        
        // 3. 已经访问过，说明找到了环
        if (vis[i][j]) return true;

        // 标记当前格子为已访问
        vis[i][j] = true;

        // 4. 遍历四个方向
        for (auto& d : dir) {
            int ni = i + d[0];
            int nj = j + d[1];


            // 跳过「直接回退到上一步」的格子！！！！！！！！！！！！！
            if (ni == pi && nj == pj) continue;


            // 递归搜索，如果找到环直接返回true
            if (dfs(ni, nj, i, j, grid, vis, c)) {
                return true;
            }
        }

        // 四个方向都没找到环
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // 访问标记数组，初始化全为false
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // 遍历每个格子，作为起点开始搜索
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!vis[i][j]) {
                    // 第一次搜索，上一步的位置设为(-1,-1)，不会被命中
                    if (dfs(i, j, -1, -1, grid, vis, grid[i][j])) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};