class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        ans = nums[0]
        first_min = 51
        second_min = 51

        for num in nums[1:]:
            if num < first_min:
                second_min = first_min
                first_min = num
            elif num < second_min:
                second_min = num

        return ans + first_min + second_min

        