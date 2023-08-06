class Solution:
    def reverseVowels(self, s: str) -> str:
        s = list(s)
        m = 'aeiouAEIOU'
        left = 0
        right = len(s)-1
        while left<=right:
            if (s[left] in m) and (s[right] in m):
                s[left],s[right] = s[right],s[left]
                left+=1
                right-=1
            elif s[left] in m:
                while right>=left and (s[right] not in m):
                    right-=1
            elif s[right] in m:
                while right>=left and (s[left] not in m):
                    left+=1
            else:
                left+=1
                right-=1
        return ''.join(s)
            