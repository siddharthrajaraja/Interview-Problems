class Solution:
    
    def checkValidString(self, s: str) -> bool:
        stack=[]
        for i in range(0,len(s)):
            if s[i]=='(' or s[i]=='*':
                stack.append(s[i])
            else:
                if len(stack)==0 :
                    return False
                stars=0
                flag=0
                while len(stack)!=0:
                    
                    ele=stack[-1]
                    
                    stack.pop()
                    if ele=='*':
                        stars+=1
                    if ele=='(':
                        flag=1
                        break
                
                if len(stack)==0 and flag!=1:
                    
                    if stars!=0:
                        stars-=1
                while stars!=0:
                        stack.append('*')
                        stars-=1
                            
            print(stack)
        print("I am out")
        stars=0
        openb=0
        
        if(list(set(stack))==['*']):
            return True
        
        while True:
            if(len(stack)==0) or (list(set(stack))==['*']):
                return True
            stars=0
            while len(stack)!=0:
                ele=stack[-1]
                stack.pop()
                if ele=='(':
                    break
                stars+=1
                
            if stars==0:
                return False
            stars-=1
            while stars!=0:
                stars-=1
                stack.append('*')
            
            print(stack)        
                    
                
                
        