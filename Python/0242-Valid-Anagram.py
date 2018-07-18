    def isAnagram(self, s, t):
        // Method 1
        return sorted(s) == sorted(t)
        
        // Method 2
        if len(s) != len(t):
            return False
        d = dict((letter, 0) for letter in string.ascii_lowercase)
        
        for (a, b) in zip(s, t):
            d[a] += 1
            d[b] -= 1

        return not reduce(lambda x,y: x or y, d.values(), False)
