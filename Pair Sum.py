n=int(input())
l=[]
for i in range(0,n):
    l.append(int(input()))
k=int(input())

ans=[]
for i in range(0,len(l)):
    if k-l[i] in l:
        sol1=(l[i],k-l[i])
        sol2=(k-l[i],l[i])
        if sol1 not in ans or sol2 not in ans:
            ans.append(sol1)
#print(ans)
for i in range(0,len(ans)//2):
    print(ans[i][0],"and",ans[i][1])
    
        
   