// Given a non-negative integer x, return the square root of x rounded down to the nearest integer. 
// The returned integer should be non-negative as well.

// You must not use any built-in exponent function or operator.

// For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

// Example 1:

// Input: x = 4
// Output: 2
// Explanation: The square root of 4 is 2, so we return 2.

#include <iostream>
using namespace std;

int mySqrt(int x) {
    if (x == 0 || x == 1)
        return x;

    int low = 1;
    int high = x;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (mid <= x / mid) {
            // mid * mid <= x
            ans = mid;
            low = mid + 1;
        }
        else {
            // mid * mid > x
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int x;
    cin >> x;

    cout << mySqrt(x);

    return 0;
}