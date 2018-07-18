    def reverse(self, x):
        return [1, -1][x < 0] * int(str(abs(x))[::-1]) if - 2 ** 31 <= [1, -1][x < 0] * int(str(abs(x))[::-1]) <= 2 ** 31 - 1 else 0
