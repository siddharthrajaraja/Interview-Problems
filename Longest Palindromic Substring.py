s=list(input())

for i in range(0,len(s)):
    for j in range(i+1,len(s)):
        #print(s[i:j])
        m=s[i:j]
        print(m)
        if len(m)%2!=0:
            mr=m[i:j//2]
            ml=m[j//2:]
            ml.reverse()
        else:
            mr=m[i:j//2+1]
            ml=m[j//2:]
            ml.reverse()
            
        if mr==ml:
            print("".join(m))
                
