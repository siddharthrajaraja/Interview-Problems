n=int(input())
l=list(map(int,input().split()))

positive=list(map(int,'0'*1000000))
negative=list(map(int,'0'*1000000))
zeroes=0
for i in range(0,len(l)):
    if l[i]<0:
        negative[abs(l[i])]+=1
    elif l[i]>0:
        positive[l[i]]+=1
    elif l[i]==0:
        zeroes+=1
ans=[]

if zeroes==1:
    ans=[0]

for i in range(0,len(negative)):
    if negative[i]==1:
        
        ans.append(-1*i)
    if positive[i]==1:
        ans.append(i)
for i in range(0,len(ans)):
    print(ans[i])
#print(ans)
        
    
        
