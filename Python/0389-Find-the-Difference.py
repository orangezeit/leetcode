    from functools import reduce
    def findTheDifference(self, s, t):
        return reduce(lambda x,y: chr(ord(x)^ord(y)), list(s+t))
