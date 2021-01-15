#include <bits/stdc++.h>
using namespace std;
#define umap unordered_map
#define vs vector<string>
#define vvs vector<vs>

#define REP(i, a, b) for (int i = a; i < b; i++)

    
   
class Solution
{

public:
    struct emailID;
    struct username;
    
    typedef struct emailID
    {
        string s;
        struct username *next;

    } emailID;

    typedef struct username
    {
        string s;
        set<struct emailID *> allEmailsLinked;
    } username;



    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        
    umap<struct username *, bool> parentDic;
    umap<string, struct  emailID *> emailAdd;
    umap<string, bool> emailDic;

        for (auto ele : accounts)
        {

            string uname = ele[0];
            vs every = ele;
            int size = every.size();

            int i;
            set<username*> commonUsernames; // this gives all commonUsernames to maintain transitivity

            REP(i, 0, size)
            {
                if (emailDic[every[i]])
                {
                    commonUsernames.insert(emailAdd[every[i]]->next);
                }
            }

            if (!commonUsernames.empty())
            { // there exists more than one users with same emailID may be multiple
                auto parentUname = *commonUsernames.begin();
                parentDic[parentUname] = true;

                for (auto it = commonUsernames.begin(); it != commonUsernames.end(); it++)
                {
                    if(it!=commonUsernames.begin()){
                        set<emailID *> emailsLinked = (*it)->allEmailsLinked;
                        parentDic[*it] = false;

                        for (auto visitAllEmailsLinked : emailsLinked)
                        {
                            visitAllEmailsLinked->next = parentUname;
                            parentUname->allEmailsLinked.insert(visitAllEmailsLinked);
                        }
                    }
                }

                REP(i, 1, size)
                {
                    emailID *newEmail = new emailID;
                    newEmail->next = parentUname;
                    parentUname->allEmailsLinked.insert(newEmail);
                    emailAdd[every[i]] = newEmail;
                    emailDic[every[i]] = true;
                    newEmail->s = every[i];
                }
            }
            else
            {
                username *newUser = new username;
                parentDic[newUser] = true;
                newUser->s = uname;
                newUser->allEmailsLinked = {};

                REP(i, 1, size)
                {
                    emailID *newEmail = new emailID;
                    newEmail->next = newUser;
                    newUser->allEmailsLinked.insert(newEmail);
                    emailAdd[every[i]] = newEmail;
                    emailDic[every[i]] = true;
                    newEmail->s = every[i];
                }
            }
        }
        
        vvs res;

        for(auto everyParent:parentDic){
            if(everyParent.second){
                
                auto parent=everyParent.first;
                
                res.push_back({parent->s});
                
                set<string>finalEmails;
                
                for(auto everyString:parent->allEmailsLinked){
                    finalEmails.insert(everyString->s);
                    
                }
                
                for(auto everyMail:finalEmails){
                    res.back().push_back(everyMail);    
                }
                

            }
        }
        return res;
    }
};