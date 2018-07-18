    def containsNearbyDuplicate(self, nums, k):
        d = {}
        for i,n in enumerate(nums):
            if n in d and i - d[n] <= k:
                return True
            else:
                d[n] = i
        return False
