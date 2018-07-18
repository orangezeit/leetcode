    def reverseStr(self, s, k):
        ss = re.findall(".{" + str(k) + "}", s)
        ss.append(s[len(s) // k * k:])
        return ''.join([ss[i][::-1], ss[i]][i % 2] for i in range(len(ss)))
