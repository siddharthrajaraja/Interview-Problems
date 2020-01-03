s1=list(input())
s2=list(input())


def checkCount(s1,s2):
    for i in range(0,len(s2)):
        if s1.count(s2[i])<s2.count(s2[i]):
            return 0
    return 1
mini=100000000
ans=[[]]
for i in range(0,len(s1)-len(s2)):
    for j in range(i+len(s2),len(s1)):
        if checkCount(s1[i:j],s2)==1 and len(s1[i:j])<mini:
            mini=len(s1[i:j])
            ans[0]=s1[i:j]
print("".join(ans[0]))
        