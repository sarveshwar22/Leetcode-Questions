class Solution:
    def reverseWords(self, s: str) -> str:
        res = []
        temp = ""
        for ch in s:
            if ch==' ':
                if temp != "":
                    res.append(temp)
                    temp=""
            else:
                temp+=ch
        if temp!="":
            res.append(temp)
        return " ".join(res[::-1])
        