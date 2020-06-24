<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/css/materialize.min.css">
<h5><strong> <i> Maps that allows you hash stuff together!! 😄  <i> <strong> <h5>
<hr>
    <strong>Longest Fibonacci Subsequence : </strong><a href="https://practice.geeksforgeeks.org/problems/largest-fibonacci-subsequence/0/">G4G</a>
    <br>
    <strong>Intution:</strong>
    <ol>
        <li>Pecompute a bitmap for every Fib term .
        <li>Map the input with the bitmap obtained and print the output if the input exists in the bitmap.</li>
    </ol>
<hr>

#### Longest Consecutive Sequence

###### Link to problem 👍 [Leetcode](https://leetcode.com/problems/longest-consecutive-sequence/)

##### Intution:
    1. Try to minimize the array-size by removing similar elements and sort the given array.
    2. Can you index the elements present in the set to directly refer them anyhow?
    3. Hash and maintain a flag to check which element exists (a typical intution of Counting Sort Algorithm) or simply iterate that set to form a new vector.
    4. Initialize maxii (maximum consecutive counter) to INT_MIN to get the maximum consecutive size of Longest Consecutive Sequence.
    4. For every index in the array/vector (1:vector.size()) check whether the previous element is predecessor or not .
    4. If "YES" : increment the counter.
    5. Otherwise reinitialize value of maxii to counter and reinitialize counter to 1.
    6. Return maxii (maximum consecutive counter). 

****
