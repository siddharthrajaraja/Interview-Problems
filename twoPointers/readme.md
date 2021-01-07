# Point to different indices and feel more powerful!!

#### CONTAINER WITH MOST WATER (REAL LIFE):

*Link to problem :* [Leetocode](https://leetcode.com/problems/container-with-most-water/)

*Algorithm:*
    
    1. In the provided list of values place two pointers i,j such that both of them lies in extreme corners of the list.
    2. Calculate area as:
            Area=Width*Height
            Width=(j-i)
            Height=min(height[j],height[i])
    3. Look for maximum of the obtained area.
    4. Change the values of i and j greedily.
    5. Return maximum area obtained.   

***

#### Longest Substring Without Repeating Characters

*Link to problem :*[Leetcode](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/579/week-1-january-1st-january-7th/3595/)

*Algorithm:*
        * Try to think of a two pointer based solution.
        * One pointer pointer placed at end of current String and maintain each character in current string using hashmap.
        * Can you minimize use of Two pointers with an equivalent Data Structure (Hint : Linear Data Structure?).
        * Time Complexity : O(n)
        * Space Complexity : O(n) 

