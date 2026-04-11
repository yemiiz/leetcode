//3741. Minimum Distance Between BST Nodes
//优化：直接用哈希表存每个数字的下标列表，只遍历一次nums，时间复杂度O(n)，空间复杂度O(n)

#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int minimumDistance(vector<int> &nums)
    {
        
        int dis = 200000;

        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < nums.size(); i++)
        {
            pos[nums[i]].push_back(i);
        }

        for (auto &[num, posi] : pos)
        {

            for (int k = 0; k <= (int)posi.size() - 3; k++)
            {
                dis = min(dis, 2 * (posi[k + 2] - posi[k]));
            }
        }

        return dis == 200000 ? -1 : dis;
    }
};