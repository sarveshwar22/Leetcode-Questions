class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if(str1+str2 != str2+str1):
            return ""
        m,n = len(str1),len(str2)
        from math import gcd
        return str1[:gcd(m,n)]
        