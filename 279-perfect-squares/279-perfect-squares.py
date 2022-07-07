import math

class Solution:
    def numSquares(self, n: int) -> int:
        if math.sqrt(n)%1 == 0:
            return 1

        hashmap = dict()
        for i in range(n):
            if i * i > n:
                break

            hashmap[i * i] = 1

            if (n - i * i) in hashmap.keys():
                return 2

       #Legendre's three-square theorem O(log(n)) presumably
        while n > 0 and n % 4 == 0:
            n /= 4
        if n % 8 != 7:
            return 3
        
        
        else:  
            #Lagrange's four-square theorem
            return 4
        