<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/css/materialize.min.css">
<blockquote> <strong> <i> Those who cannot remember the past they are condemned to repeat it.<i></strong> </blockquote>

<h5><strong> 😫 <i> Try Some simple DP PROBLEMS . This makes you feel 😄  <i> <strong> <h5>
<hr>
    <strong>Longest Common Subsequence : </strong><a href="https://leetcode.com/problems/longest-common-subsequence/">Link to problem</a>
<hr>
    <strong>Shortest Common Supersequence : </strong><a href="https://leetcode.com/problems/shortest-common-supersequence/">Link to problem</a>
    <br>
    Intution 🤔 👍 --> <br>
    <ol>
            <li>Try Finding out LCS string.
            <li>With the obtained LCS try integrating the non LCS character in such a way that they occur in the same order of their appearance in their desired strings.
            <li>The solution string is union of LCS and non LCS characters in order of their apprearance. 
    </ol>
<hr>
    <strong>Longest Arithematic Progression : </strong><a href="https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression/0">Link to problem</a>
    <br>
    Intution 🤔 👍 💯 --> <br>
    <ol>
            <li>Try to figure out O(n*n) Logic with a hint of storing the common difference between each pair of elements when iterated. 
            <li>Try to build a Hash Map dynamically from index (1:size of array) in such a way that Hash Map stores the elements of type {key(common difference):value(counter)} which is referenced for each pair from previously iterated index.
            <li>Try to find out the max counter present in the Hash Map . The (max+1) will give you solution . Guess why?
            <li>Pairing elements helps you find the solution reason for adding 1 behind max is the same as one need to count elements that are paired together. 
    </ol>
<hr>
    <strong>Edit Distance : </strong><a href ="https://leetcode.com/problems/edit-distance/">Leetcode</a> or <a href="https://practice.geeksforgeeks.org/problems/edit-distance/0">G4G</a>
    <br>Intution:<br>
    <div style="text-align:center">    
    <img src="./images/editDistance.jpeg" width="600px">
    </div>
<hr>
    <strong>Longest Palindromic Subsequence : </strong><a href ="https://leetcode.com/problems/longest-palindromic-subsequence/">Leetcode</a> 
    <br>Intution:<br>
   <ol>
            <li>Similar to LCS.</li>
            <li>Just need to find LCS of string and reversed string and return length of LCS.</li> 
    </ol>