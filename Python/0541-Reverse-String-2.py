    def reverseStr(self, s, k):
        return ''.join([n[::-1], n][i % 2] for i, n in enumerate(re.findall(".{" + str(k) + "}", s) + [s[len(s) // k * k:]]))
