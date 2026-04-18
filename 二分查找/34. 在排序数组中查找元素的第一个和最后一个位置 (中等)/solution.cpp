class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        if (lower_bound(nums.begin(), nums.end(), target) != nums.end() && *lower_bound(nums.begin(), nums.end(), target) == target)
        //if(lower_bound(nums.begin(),nums.end(),target)!=nums.end()&&nums[lower_bound(nums.begin(),nums.end(),target)]==target)
        {
            //ans.push_back(lower_bound(nums.begin(),nums.end(),target));
            //ans.push_back(upper_bound(nums.begin(),nums.end(),target)-1);
            int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

            int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
            ans.push_back(left);
            ans.push_back(right);
        }
        else
        {
            ans.push_back(-1);
            ans.push_back(-1);

        }
        return ans;
    }
};