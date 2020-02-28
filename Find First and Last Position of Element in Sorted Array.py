def binSearch(nums,target):
    if nums ==[]:
        return -1
    l=0
    u=len(nums)-1
    while l<=u:
        m=(l+u)//2
        if nums[m]==target:
            return m
        elif nums[m]>target:
            u=m-1
        else:
            l=m+1
    return -1
            
    
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if binSearch(nums,target)==-1:
            return [-1,-1]
        else:
            m=binSearch(nums,target)
            j=m
            i=m
            print(m)
            while i>=0:
                if nums[i]!=target:
                    break
                i=i-1
            
            while j<len(nums):
                if nums[j]!=target:
                    break
                j=j+1
            
            return [i+1,j-1]
                    
        
        