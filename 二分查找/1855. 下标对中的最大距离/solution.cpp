class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxDist = 0;
        int n = nums1.size(), m = nums2.size();

        for (int i = 0; i < n; i++) {
            // 在nums2中二分查找第一个小于nums1[i]的位置
            int left = i, right = m - 1;
            int pos = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums1[i] <= nums2[mid]) {
                    pos = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            if (pos != -1) {
                maxDist = max(maxDist, pos - i);
            }
        }
        return maxDist;
    }
};