class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        rv = []
        candidates.sort()
        
        def add(l,pos):
            if sum(l)<target:
                for i in range(pos,len(candidates)):
                    if i!=pos and candidates[i-1]==candidates[i]:
                        continue
                    add(l+[candidates[i]],i+1)
            elif(sum(l)==target):
                rv.append(l)
        
        add([],0)
        return rv