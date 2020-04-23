def count_digits(n):
    if n==0:
        return 0
    return 1+count_digits(n//10)

n=int(input())

digits=count_digits(n)
print(digits)
