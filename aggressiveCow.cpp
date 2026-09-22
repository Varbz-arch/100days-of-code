// Problem Statement
// Given n stalls located at different positions along a straight line and k cows, place the cows in the stalls such that the minimum distance between any two cows is maximized.

// This is an optimization problem where binary search on the answer is required.

// Input Format
// n k
// n space-separated integers representing stall positions

// Output Format
// Print the maximum possible minimum distance between any two cows.

// Sample Input
// 5 3
// 1 2 8 4 9

// Sample Output
// 3

// Explanation
// Cows can be placed at positions 1, 4, and 8. The minimum distance between any two cows is 3, which is the maximum possible.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlaceCows(vector<int>& stalls, int k, int minDist) {
    int cowsPlaced = 1;
    int lastPosition = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPosition >= minDist) {
            cowsPlaced++;
            lastPosition = stalls[i];
        }

        if (cowsPlaced >= k) {
            return true;
        }
    }

    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> stalls(n);

    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }

    // Sort stall positions
    sort(stalls.begin(), stalls.end());

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int answer = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, k, mid)) {
            // mid distance is possible
            answer = mid;

            // Try for an even larger distance
            low = mid + 1;
        } else {
            // mid distance is not possible
            high = mid - 1;
        }
    }

    cout << answer << endl;

    return 0;
}