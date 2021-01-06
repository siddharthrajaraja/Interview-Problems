#include <bits/stdc++.h>
using namespace std;
#define umap unordered_map
#define vi vector
#define pushb push_back
#define popb pop_back

class Twitter
{
public:
    /** Initialize your data structure here. */
    
    // this is to manage relations for post
    umap<int, umap<int, bool>> relations;
    
    //umap<int, vi<int>> posts;
    umap<int, vector<vector<int>>> latestFeeds;
    
    // This is for individual follower list
    umap<int,umap<int,bool>>foll;
    
    
    umap<int,vector<vector<int>>>feeds;
    
    // this is to maintain time of user posting news feed!
    int time;

    Twitter()
    {
        // posts = {};
        latestFeeds={};
        
        relations = {};
        time = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)
    {
        latestFeeds[userId].push_back({time, userId, tweetId});
        
        feeds[userId].push_back({time,userId,tweetId});
        
        for (auto ele : relations[userId])
        {
            latestFeeds[ele.first].push_back({time, userId, tweetId});
        }
        
        time++;
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        vector<int> allTweets;
        
        vector<vector<int>> allFeeds = latestFeeds[userId];
        
        sort(allFeeds.begin(),allFeeds.end());
        
        
        int count = 0;

        for (auto it = allFeeds.rbegin(); it != allFeeds.rend(); it++)
        {
            
            
            int topUser = (*it)[1];
            int topTweet = (*it)[2];
            
            
            
            if (count == 10)
                break;
            
            if(topUser==userId||foll[userId][topUser]){
                allTweets.push_back(topTweet);
                count++;
            
            }
                
        }

        return allTweets;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId)
    {   
        if(followerId==followeeId)
                return;
        try
        {
            if(relations[followerId].find(followeeId)==relations[followerId].end()){
                
                for(auto ele:feeds[followerId]){
                    latestFeeds[followeeId].push_back(ele);
                }
                
                
                for(auto ele:feeds[followeeId]){
                    latestFeeds[followerId].push_back(ele);
                }
                
            }
            relations[followerId][followeeId] = true;
            relations[followeeId][followerId] = true;
            foll[followerId][followeeId]=true;
            
        }
        catch (int x)
        {
        }
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId)
    {
        
        if(followerId==followeeId)
                return;
        
        if(relations[followerId].find(followeeId)!=relations[followerId].end()){
                relations[followeeId][followerId] = false;
                relations[followerId][followeeId] = false;
                foll[followerId][followeeId]=false; 
        }
        
    }
};
