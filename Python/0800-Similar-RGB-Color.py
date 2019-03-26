    def similarRGB(self, color):
        """
        :type color: str
        :rtype: str
        """

        return '#' + ''.join(['%2x' % ((int(c,16) // 17 + (int(c,16) % 17 > 8)) * 17) for c in [color[k:k+2] for k in range(1,6,2)]]).replace(' ', '0')
