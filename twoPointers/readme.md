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