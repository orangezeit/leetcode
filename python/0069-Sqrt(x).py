    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        i = 0
        j = 46341
        
        while i + 1 < j:
            m = int((i+j)/2)
            if x < m * m:
                j = m
            else:
                i = m
        
        return i
