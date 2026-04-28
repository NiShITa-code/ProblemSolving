class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        nums = []
        result = 0

        for row in grid:
            for num in row:
                nums.append(num)

        nums.sort()
        length = len(nums)
        final_num = nums[length//2]

        for num in nums:
            if num % x != final_num % x:
                return -1
            result +=abs(final_num - num)//x
        
        return result