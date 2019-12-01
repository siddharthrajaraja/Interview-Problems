n=int(input())
l=list(map(int,input().split()))
c=0
flag=0
for i in range(1,len(l)):
    if l[i]<l[i-1]:
        c=c+1
    if c>1:
        print("flase")
        
        break
        
if c<=1:
    print("true")
        
