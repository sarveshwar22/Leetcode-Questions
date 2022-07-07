class Solution:
    
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        
        seen = set()
        def recursive(s, t, remaining):
            if len(s) == len(t) == len(remaining) == 0:
                return True

            ans = False

            if len(s) > 0 and len(remaining) > 0 and s[0] == remaining[0] and (s[1:]+'.'+t not in seen or t[1:]+'.'+s not in seen):
                seen.add(s[1:]+'.'+t)
                ans = recursive(s[1:],t,remaining[1:])



            if len(t) > 0 and len(remaining) > 0 and t[0] == remaining[0] and (s[1:]+'.'+t not in seen or t[1:]+'.'+s not in seen):
                seen.add(t[1:]+'.'+s)
                ans = ans or recursive(s, t[1:], remaining[1:])



            return ans

        return recursive(s1, s2, s3)