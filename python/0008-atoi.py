    def myAtoi(self, str):
        str = str.lstrip()
        
        if str == "":
            return 0
        elif str[0].isnumeric() or str[0] == '-' or str[0] == '+':
            for i in range(1, len(str)):
                if not str[i].isnumeric():
                    str = str[:i]
                    break
            
            if str == "-" or str == "+":
                return 0
            elif int(str) > 2147483647:
                return 2147483647
            elif int(str) < -2147483648:
                return -2147483648
            else:
                return int(str)
        else:
            return 0
