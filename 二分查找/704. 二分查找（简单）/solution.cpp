class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = -1,r = nums.size();
        while(l+1 < r)
        {
            int mid = l+(r-l)/2;
            if(nums[mid]<target)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        if(r < nums.size() && nums[r] == target)    //会越界！！
        {
            return r;
        }
        else{
            return -1;
        }
    }
};