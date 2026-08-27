// There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

// When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

// Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.

 

// Example 1:

// Input: rooms = [[1],[2],[3],[]]
// Output: true
// Explanation: 
// We visit room 0 and pick up key 1.
// We then visit room 1 and pick up key 2.
// We then visit room 2 and pick up key 3.
// We then visit room 3.
// Since we were able to visit every room, we return true.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n;

    printf("Enter number of rooms: ");
    scanf("%d", &n);

    int** rooms = malloc(n * sizeof(int*));
    int* roomsColSize = malloc(n * sizeof(int));

    // Input keys for each room
    for (int i = 0; i < n; i++) {
        printf("Enter number of keys in room %d: ", i);
        scanf("%d", &roomsColSize[i]);

        rooms[i] = malloc(roomsColSize[i] * sizeof(int));

        printf("Enter keys: ");
        for (int j = 0; j < roomsColSize[i]; j++) {
            scanf("%d", &rooms[i][j]);
        }
    }

    // visited array
    bool* visited = calloc(n, sizeof(bool));

    // Stack for DFS
    int* stack = malloc(n * sizeof(int));
    int top = 0;

    // Start from room 0
    stack[top++] = 0;
    visited[0] = true;

    // DFS
    while (top > 0) {
        int room = stack[--top];

        for (int i = 0; i < roomsColSize[room]; i++) {
            int key = rooms[room][i];

            if (!visited[key]) {
                visited[key] = true;
                stack[top++] = key;
            }
        }
    }

    // Check whether all rooms were visited
    bool allVisited = true;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            allVisited = false;
            break;
        }
    }

    if (allVisited)
        printf("true\n");
    else
        printf("false\n");

    // Free memory
    for (int i = 0; i < n; i++) {
        free(rooms[i]);
    }

    free(rooms);
    free(roomsColSize);
    free(visited);
    free(stack);

    return 0;
}