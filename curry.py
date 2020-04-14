
class addSubtract(int):
    list=[]
    def __call__(self, v):
          self.list.append(v)
          return type(self)(v)
    def printList(self):
          print("yaha hu",self.list)
    def getResult(self):
          if len(self.list)==0:
                return 0
          s=self.list[0]
          for i in range(1,len(self.list)):
                if i%2==0:
                      s=s-self.list[i]
                else:
                      s=s+self.list[i]
          return s
print(addSubtract()(7).getResult())