## Union Find implements Disjoint Set Units data structures here with Speghatti Stack implementation.

---

## [Accounts-Merge](https://leetcode.com/problems/accounts-merge/)

    * Intution :
        * The problem seems to be simply a graph traversal.
        * Other way to visualize is implementing DSU to maintain transitivity.
        * Think of a username to be a node and email to be other node with different structures (C/C++) 😆 specific.
        * Now try to merge the two emailIDs belonging to users having same emailIDs.
        * Remember separate hashmaps are used to maintain whether a emailID exists or not with any user.

_Note : Two or more users may be merged think of a logic in linear time to merge the users with similar emailID and remove either of the user(condition mentioned username remains same)._

        * To return the result maintain set of string and fullfill requirements.
