class Solution:
    def findMin(self, nums: list[int]) -> int:
        left = 0
        right = len(nums) - 1
        
        while left < right:
            mid = (left + right) // 2
            if nums[mid] > nums[right]:
                # 最小值在 mid 右侧
                left = mid + 1
            else:
                # 最小值在 mid 或 mid 左侧
                right = mid
        
        return nums[left]