n=int(input())
l=list(map(int,input().split()))
k=int(input())
for i in range(0,len(l)-k+1):
    m=l[i:i+k]
    print(len(list(set(m))))

