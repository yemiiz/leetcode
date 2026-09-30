            ok |= dfs(i, j+1, bal, grid);
        }
        return ok;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int len = m + n -1;
        if(len % 2 == 1) return false;
        int maxBal = len / 2;
        vis.assign(m, vector<vector<bool>>(n, vector<bool>(maxBal+1, false)));
        return dfs(0,0,0,grid);
    }
};
