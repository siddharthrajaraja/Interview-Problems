## [Create Sorted Array through Instructions](https://leetcode.com/problems/create-sorted-array-through-instructions/)

    * Intution :
        * Think of a brute force solution similar to A Counting Sort Algortim.
        * Can you perform any sort of optimizations, may be including prefix sums?
        * Is this optimization the best solution?
        * Can you optimize it more implementing a Fenwick Tree?
        * Hint :
            sum=(sum+ min(getSum(ele-1),getSum(maxi)-getSum(ele)))

                * here maxi is (maximum of the elements present in array)+1
                * getSum(ele) : Sum of range of values from 1 to ele (in prefix Count FenTree Array)
                * getSum(ele-1) 😆 conclude from above.

---
