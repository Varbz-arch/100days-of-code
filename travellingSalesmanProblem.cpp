// Given a 2d matrix cost[][] of size n where cost[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from city 0 (0-based index) to all other cities such that you visit each city exactly once and then at the end come back to city 0 at minimum cost.

// Examples:

// Input: cost[][] = [[0, 111], 
//                 [112, 0]]
// Output: 223
// Explanation: We can visit 0->1->0 and cost = 111 + 112.

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int tsp(vector<vector<int>>& cost) {
    int n = cost.size();

    // Edge case: only one city
    if (n == 1) {
        return 0;
    }

    int totalMasks = 1 << n;

    // dp[mask][city]
    // Minimum cost to visit all cities in mask
    // and currently be at 'city'
    vector<vector<int>> dp(
        totalMasks,
        vector<int>(n, INT_MAX)
    );

    // Start from city 0
    dp[1][0] = 0;

    // Try every visited-city combination
    for (int mask = 1; mask < totalMasks; mask++) {

        for (int city = 0; city < n; city++) {

            // If city is not visited
            if (!(mask & (1 << city))) {
                continue;
            }

            // If this state is unreachable
            if (dp[mask][city] == INT_MAX) {
                continue;
            }

            // Try going to every unvisited city
            for (int next = 0; next < n; next++) {

                // If next city is already visited
                if (mask & (1 << next)) {
                    continue;
                }

                int newMask = mask | (1 << next);

                dp[newMask][next] = min(
                    dp[newMask][next],
                    dp[mask][city] + cost[city][next]
                );
            }
        }
    }

    // All cities have been visited
    int fullMask = (1 << n) - 1;

    int answer = INT_MAX;

    // Return from the last city back to city 0
    for (int city = 1; city < n; city++) {

        answer = min(
            answer,
            dp[fullMask][city] + cost[city][0]
        );
    }

    return answer;
}

int main() {

    int n;

    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    cout << tsp(cost) << endl;

    return 0;
}