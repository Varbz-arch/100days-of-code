# Given an integer n, return true if it is a power of two. Otherwise, return false.
# An integer n is a power of two, if there exists an integer x such that n == 2x.
# Example 1:
# Input: n = 1
# Output: true
# Explanation: 20 = 1

def isPowerOfTwo(n):
    if n == 1:
        return True

    if n <= 0 or n % 2 != 0:
        return False

    return isPowerOfTwo(n // 2)

# Input
n = int(input())

# Output
print(isPowerOfTwo(n))