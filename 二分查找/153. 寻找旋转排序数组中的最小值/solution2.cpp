from typing import List

class Solution:
    # 标准方法：左闭右闭区间 [left, right]（推荐）
    def findMin(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        while left < right:
            mid = (left + right) // 2
            if nums[mid] < nums[left]:
                left = mid + 1          # 最小值在右侧
            else:
                right = mid             # 最小值在左侧（含mid）
        return nums[left]
    
    # 方法2：左闭右开区间 [left, right)
    def findMin2(self, nums: List[int]) -> int:
        left, right = 0, len(nums)
        while left < right:
            mid = (left + right) // 2
            if nums[mid] > nums[right - 1]:
                left = mid + 1
            else:
                right = mid
        return nums[left]
    
    # 方法3：左右都开区间 (left, right)
    def findMin3(self, nums: List[int]) -> int:
        left, right = -1, len(nums)
        while left + 1 < right:
            mid = (left + right) // 2
            if nums[mid] > nums[right - 1]:
                left = mid
            else:
                right = mid
        return nums[right]