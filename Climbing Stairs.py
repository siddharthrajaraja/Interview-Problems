class Solution:
    def climbStairs(self, n: int) -> int:
        if n==0:
            return 0
        if n==1:
            return 1
        
        arr=[0,1]
        
        while n!=0:
            arr.append(arr[-1]+arr[-2])
            n=n-1
        return arr[-1]