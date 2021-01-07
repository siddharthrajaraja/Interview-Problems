class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        deque<char>Q;
        map<char,bool>dic;
        int count=0;
        int maxi=0;
        
        for(auto ele:s){
            
            if(dic[ele]==false){
                Q.push_back(ele);
                dic[ele]=true;
                count++;
            }
            else{
                
                
                while(!Q.empty()){
                    char front=Q.front();
                    dic[front]=false;
                    Q.pop_front();
                    count--;
                    if(front==ele){
                        Q.push_back(ele);
                        dic[ele]=true;
                        count++;
                        break;
                    }
                }
                
                
            }
            maxi=max(maxi,count);
            
        }
        maxi=max(maxi,count);
        return maxi;
        
    }
};