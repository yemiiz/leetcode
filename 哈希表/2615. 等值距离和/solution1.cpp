class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        vector<long long>ans;
        unordered_map<int,vector<int>>mp;
        for(int i = 0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);

        }
        for(int i = 0;i<nums.size();i++)
        {
            if(!mp.count(nums[i]))
            {
                ans.push_back(0ll);
            }
            else
            {
                long long ans1 = 0ll;
                for(int j =0;j<mp[nums[i]].size();j++)
                {
                    ans1+=abs(i-mp[nums[i]][j]);

                }
                ans.push_back(ans1);
                
            }
        }
        return ans;
    }
};