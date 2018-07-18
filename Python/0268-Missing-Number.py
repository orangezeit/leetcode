    from functools import reduce
    def missingNumber(self, nums):
        return len(nums) * (len(nums) + 1) // 2 - reduce(lambda x,y: x+y, nums, 0)
