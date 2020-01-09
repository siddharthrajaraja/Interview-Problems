l=list(map(int,input().split()))
l.pop()
k=l[::]
k.reverse()

if k==l:
    print("true")
else:
    print("false")