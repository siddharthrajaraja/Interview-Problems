# Some intutive problems on Matrix 😸

---

## [Search in 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/submissions/)

```
Algorithm :

    1) put a pointer (x,y) at (0,C-1)

    2) while(1):

        a)  if invalid(x,y):
                return False

        b)  currentElement = mat[x][y]

        c)  if currentElement==target:
                break

        c)  if currentElement > target : (This is because allElements in same row lesser then currentElement)
                x++
            else: (This is because allElements in same column greater then currentElement)
                y--

    3) return True
```

---
