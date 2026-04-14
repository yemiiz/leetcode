//核心：分配不得交叉
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());//二维数组也可直接sort，先比较第一个元素再比较第二个元素
        int n = robot.size(), m = factory.size();//m为工厂数量
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LONG_LONG_MAX / 2));
        for (int j = 0; j <= m; j++) {
            dp[0][j] = 0;
        }
        for (int j = 1; j <= m; j++) {
            for (int i = 1; i <= n; i++) {
                dp[i][j] = dp[i][j - 1];
                long long cost = 0;
                for (int k = 1; k <= min(i, factory[j - 1][1]); k++) {
                    cost += abs((long long)robot[i - k] - factory[j - 1][0]);
                    dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + cost);
                }
            }
        }
        return dp[n][m];
    }
};

//力扣官方题解
