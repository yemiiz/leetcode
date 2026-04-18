//3741. Minimum Distance Between BST Nodes
//我的解法 （暴力法，时间复杂度O(n^2)，空间复杂度O(n)） 运行超时

#include <vector>
using namespace std;
class Solution
{
public:
    int minimumDistance(vector<int> &nums)
    {
        vector<int> count(100001, 0);   //题目设定元素范围为0-100000，要初始化为0，不然下面count[i]++会出问题
        vector<int> cnt2;
        vector<int> cnt3;
        for (int i = 0; i < nums.size(); i++)
        {
            count[nums[i]]++;
        }
        for(int i = 0; i < count.size(); i++)
        {
            if(count[i] >= 3)
            {
                cnt2.push_back(i);
            }
        }
        int dis = 200000;

        for(int i = 0; i < cnt2.size(); i++)
        {


            for(int j = 0; j < nums.size(); j++)
            {
                if(nums[j] == cnt2[i])
                {
                    cnt3.push_back(j);
                }
                
            }
            //这里不能套入内存循环
            for (int k = 0; k < cnt3.size() - 2; k++)
            {
                dis = min(dis, 2 * (cnt3[k + 2] - cnt3[k]));
            }
            cnt3.clear();   //记得清空cnt3，否则会有重复元素，导致结果错误
        }
        return dis == 200000 ? -1 : dis;
    }
};