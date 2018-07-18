    def convertToBase7(self, num):
        s = ""
        sign = ["", "-"][num < 0]
        num = abs(num)
        while (num):
            s += str(num % 7)
            num //= 7
        return sign + "".join(reversed(s))
