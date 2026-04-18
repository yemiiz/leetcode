#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>>mp;
        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]].push_back(i);
        }
        /*
        for(auto it = nums.begin();it!=nums.end();it++)
        {
            mp[nums[it]].push_back(it)这里不能push_back iteratorr; //push_back not insert
        }
        */
        vector<int>ans;
        for(auto it = 0;it!=queries.size();it++)
        {
            int ans1 = -1;
           int q = queries[it]; 
            if(mp[nums[q]].size()>=2) 
            {
                auto& vec = mp[nums[q]];    //！！！
                int len = vec.size();

                int pos = lower_bound(vec.begin(), vec.end(), q) - vec.begin(); //lower_bound找到第一个出现q的位置！！    lower_bound只能在有序容器里使用

                int pre = vec[(pos-1+len)%len];
                int nxt = vec[(pos+1)%len];
                int n = nums.size();

                ans1 = min( min(abs(q-pre), n-abs(q-pre)), min(abs(q-nxt), n-abs(q-nxt)) );
            }
            ans.push_back(ans1);
        }
        return ans;
    }
};
