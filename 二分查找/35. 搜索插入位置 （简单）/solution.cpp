class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = -1,r = nums.size();
        while(l+1<r)
        {
            int mid = l+(r-l)/2;
            if(nums[mid]<target)   //不能等于，题目要求大于等于则取小于
//只要 nums[mid] < target，不管区间是怎么定义的，答案一定在 mid 的右边。
//只有 nums[mid] >= target 时，答案才可能在 mid 或 mid 的左边。
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        return r;
    }
};