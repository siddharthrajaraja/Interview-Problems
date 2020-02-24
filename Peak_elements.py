ans=[]
solutions=[]
def check(arr,l,u):
    if l<=u:
        m=(l+u)//2
        #print(l,u,m)
        if m!=0 and m!=len(arr)-1:
            if arr[m]>arr[m-1] and arr[m]>arr[m+1]:
                ans.append(True)
                solutions.append(arr[m])
                
        check(arr,l,m-1)
        check(arr,m+1,u)
l=list(map(int,input().split()))
check(l,0,len(l)-1)

if True in ans :
    print("YES")
    print("ALL PEAK ELEMENTS ARE :",solutions)
else:
    print("NO")
