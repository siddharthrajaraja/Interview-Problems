# Optimization of prefix sum, max-min calculations with some binaries and bitmaskings visualised as a tree.

_Note : The Fenwick Tree is just an array visualization of a tree data structure_

_Intution of twoComplement(x) :_

    * return x&(-1*x) 😄 😆 if confused try out with samples.

_Algorithm of `getParent(index)` :_

    * Find 2's complement of index
    * Bitwise AND of the original index and 2's complement  of index => (andIndex)
    * Subtract index and andIndex found above

_Algorithm of `getNext(index)` :_

    * Find 2's complement of index
    * Bitwise AND of the original index and 2's complement of index => (andIndex)
    * Add index and andIndex found above

_Note : First initialize the Fenwick Tree with the getNext() then update the Fenwick with the same._

_Note : To update the Fenwick Tree use getParent()._
