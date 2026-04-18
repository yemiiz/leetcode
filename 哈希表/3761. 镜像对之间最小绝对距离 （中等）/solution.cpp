class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>mp1,mp2;
        for(int i = 0;i<nums.size();i++)
        {
            mp1.insert(make_pair(i,nums[i]));
            mp2.insert(make_pair(i,reverse(nums[i])));
        }
        int ans = 100001;
        for(auto &[key1,value1]:mp1)
        {
            for(auto &[key2,value2]:mp2)
            {
                if(value1 == value2 && key1>key2)
                {
                    ans = min(ans,abs(key1-key2));
                }
            }
        }
        return ans==100001?-1:ans;
    }
    int reverse(int n)
    {
        int m = 0;
        while(n)
        {
            m*=10;
            m+=n%10;
            n/=10;
        }
        return m;
    }
};