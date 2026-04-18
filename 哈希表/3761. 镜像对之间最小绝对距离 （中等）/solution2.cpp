class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans = 100001;
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];

            if (mp.count(x)) {
                ans = min(ans, i - mp[x]);
            }

            int rev = reverse(x);
            mp[rev] = i;
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
