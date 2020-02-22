class Solution:
    def checkSubarraySum(self, l: List[int], s: int) -> bool:
        i=0
        j=0
        ans=0
        fg=0
        n=len(l)
        for i in range(n):
            ans=l[i]
            for j in range(i+1,n):
                ans+=l[j]
                if s==0 and ans==s:
                    return True
                elif s!=0 and ans%s==0:
                    return True
        return False
                    