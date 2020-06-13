import math


class Solution:
    def numberOfWays(self, num_people: int) -> int:
        num_people //= 2
        ans = 1
        for i in range(1, num_people + 1):
            ans *= (i + num_people)
            ans //= i
        ans //= (num_people + 1)
        return ans % 1000000007
