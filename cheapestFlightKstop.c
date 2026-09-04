// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

 

// Example 1:


// Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
// Output: 700
// Explanation:
// The graph is shown above.
// The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
// Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
// Example 2:


// Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
// Output: 200
// Explanation:
// The graph is shown above.
// The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
// Example 3:


// Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
// Output: 500
// Explanation:
// The graph is shown above.
// The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.


#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

int main() {
    int n, m;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter number of flights: ");
    scanf("%d", &m);

    int **flights = (int **)malloc(m * sizeof(int *));

    for (int i = 0; i < m; i++) {
        flights[i] = (int *)malloc(3 * sizeof(int));

        printf("Enter from, to, price for flight %d: ", i + 1);
        scanf("%d %d %d",
              &flights[i][0],
              &flights[i][1],
              &flights[i][2]);
    }

    int src, dst, k;

    printf("Enter source, destination and k: ");
    scanf("%d %d %d", &src, &dst, &k);

    int *dist = (int *)malloc(n * sizeof(int));
    int *temp = (int *)malloc(n * sizeof(int));

    // Initially all cities are unreachable
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }

    dist[src] = 0;

    // k stops = k + 1 flights
    for (int i = 0; i <= k; i++) {

        // Copy distances
        for (int j = 0; j < n; j++) {
            temp[j] = dist[j];
        }

        // Relax all flights
        for (int j = 0; j < m; j++) {

            int from = flights[j][0];
            int to = flights[j][1];
            int price = flights[j][2];

            if (dist[from] != INF &&
                dist[from] + price < temp[to]) {

                temp[to] = dist[from] + price;
            }
        }

        // Update dist
        for (int j = 0; j < n; j++) {
            dist[j] = temp[j];
        }
    }

    if (dist[dst] == INF) {
        printf("Cheapest price: -1\n");
    } else {
        printf("Cheapest price: %d\n", dist[dst]);
    }

    // Free memory
    for (int i = 0; i < m; i++) {
        free(flights[i]);
    }

    free(flights);
    free(dist);
    free(temp);

    return 0;
}