    def isIsomorphic(self, s, t):
        d = {}
        
        for (a, b) in zip(s, t):
            if a not in d.keys():
                if b not in d.values():
                    d[a] = b
                else:
                    return False
            elif d[a] != b:
                return False
        return True
