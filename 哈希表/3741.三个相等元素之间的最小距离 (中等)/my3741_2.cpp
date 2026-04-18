// 3741. Minimum Distance Between BST Nodes
// 887ms 击败 10.57 %   时间复杂度 O(n)   空间复杂度 O(n)

#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int minimumDistance(vector<int> &nums)
    {
        vector<int> count(100001, 0);
        vector<int> cnt2;
        for (int i = 0; i < nums.size(); i++)
        {
            count[nums[i]]++;
        }
        for (int i = 0; i < 100001; i++)
        {
            if (count[i] >= 3)
            {
                cnt2.push_back(i);
            }
        }

        int dis = 200000;

        // 优化：用哈希表存每个数字的下标列表，只遍历一次nums
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < nums.size(); i++)
        {
            pos[nums[i]].push_back(i);
        }

        // 直接用预处理好的下标列表，O(1)获取
        for (int num : cnt2)
        {
            auto &cnt3 = pos[num];
            for (int k = 0; k <= (int)cnt3.size() - 3; k++)
            {
                dis = min(dis, 2 * (cnt3[k + 2] - cnt3[k]));
            }
        }

        return dis == 200000 ? -1 : dis;
    }
};