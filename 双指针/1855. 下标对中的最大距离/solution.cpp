class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int maxDist = 0;
        int n = nums1.size(), m = nums2.size();

        while (i < n && j < m) {
            if (i > j) {
                j = i; // 确保j >= i
            }
            if (nums1[i] <= nums2[j]) {
                maxDist = max(maxDist, j - i);
                j++; // 尝试更大的j
            } else {
                i++; // 增加i以找到更小的nums1[i]
            }
        }
        return maxDist;
    }
};