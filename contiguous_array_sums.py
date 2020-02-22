#Consider single element to be a subarray
def checkSubarraySum(nums,k):
    s=nums[0]
    i=1
    j=0
    while i<len(nums):
        if s==k:
            return [j+1,i]
        if s<k:
            s=s+nums[i]
            #print(s)
            i=i+1
        else:
            s=s-nums[j]
            j=j+1
    return []

if __name__=="__main__":
    arr=list(map(int,input().split()))
    s=int(input())
    print(checkSubarraySum(arr,s))