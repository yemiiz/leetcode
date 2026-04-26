class Solution {
private:
    vector<int> fa;   // 父数组
    vector<int> rank; // 按秩合并用的秩数组

    // 路径压缩 find
    int find(int x) {
        if (fa[x] != x) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }

    // 按秩合并 union
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;

        if (rank[x] < rank[y]) {
            swap(x, y);
        }
        fa[y] = x;
        if (rank[x] == rank[y]) {
            rank[x]++;
        }
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        fa.resize(total);
        rank.resize(total, 1);

        // 初始化：每个元素自己是自己的父节点
        for (int i = 0; i < total; ++i) {
            fa[i] = i;
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 看上方格子
                if (i > 0 && grid[i][j] == grid[i - 1][j]) {
                    int u = i * n + j;
                    int v = (i - 1) * n + j;
                    int fu = find(u);
                    int fv = find(v);
                    if (fu == fv) {
                        // 两个点已经连通，再连一次就成环了
                        return true;
                    }
                    unite(fu, fv);
                }

                // 看左方格子
                if (j > 0 && grid[i][j] == grid[i][j - 1]) {
                    int u = i * n + j;
                    int v = i * n + (j - 1);
                    int fu = find(u);
                    int fv = find(v);
                    if (fu == fv) {
                        return true;
                    }
                    unite(fu, fv);
                }
            }
        }
        return false;
    }
};