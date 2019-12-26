l=list(map(int,input().split()))

l.pop()

if len(l)%2==0:
    l.pop(len(l)//2-1)
else:
    l.pop(len(l)//2)
#print(l)
for i in range(0,len(l)):
    print(l[i],end=" ")