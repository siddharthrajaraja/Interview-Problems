# Write your code here
n=int(input())
l=list(map(int,input().split()))
zeros=0
ans=[]
for i in range(0,len(l)):
    if l[i]!=0:
        print(l[i],end=" ")
    else:
        zeros+=1
for i in range(0,zeros):
    print(0,end=" ")
