    from functools import reduce
    def singleNumber(self, nums):
        return reduce(lambda x,y: x^y, nums, 0)
