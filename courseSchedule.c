// Description
// Editorial
// Editorial
// Solutions
// Solutions
// Submissions
// Submissions


// Code
// Testcase
// Testcase
// Test Result
// 207. Course Schedule
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

 

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0. So it is possible.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(int course, int** graph, int* graphSize,
         int* visited, int* path) {

    // Already in current recursion stack = cycle
    if (path[course])
        return false;

    // Already visited
    if (visited[course])
        return true;

    visited[course] = 1;
    path[course] = 1;

    for (int i = 0; i < graphSize[course]; i++) {
        int next = graph[course][i];

        if (!dfs(next, graph, graphSize, visited, path))
            return false;
    }

    // Remove from recursion stack
    path[course] = 0;

    return true;
}

bool canFinish(int numCourses, int** prerequisites,
               int prerequisitesSize) {

    // Adjacency list
    int** graph = malloc(numCourses * sizeof(int*));
    int* graphSize = calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        graph[i] = malloc(numCourses * sizeof(int));
    }

    // Build graph
    for (int i = 0; i < prerequisitesSize; i++) {

        int course = prerequisites[i][0];
        int prerequisite = prerequisites[i][1];

        // prerequisite -> course
        graph[prerequisite][graphSize[prerequisite]++] = course;
    }

    int* visited = calloc(numCourses, sizeof(int));
    int* path = calloc(numCourses, sizeof(int));

    // Check every course
    for (int i = 0; i < numCourses; i++) {

        if (!visited[i]) {

            if (!dfs(i, graph, graphSize, visited, path)) {

                for (int j = 0; j < numCourses; j++)
                    free(graph[j]);

                free(graph);
                free(graphSize);
                free(visited);
                free(path);

                return false;
            }
        }
    }

    // Free memory
    for (int i = 0; i < numCourses; i++)
        free(graph[i]);

    free(graph);
    free(graphSize);
    free(visited);
    free(path);

    return true;
}

int main() {

    int numCourses;
    int prerequisitesSize;

    printf("Enter number of courses: ");
    scanf("%d", &numCourses);

    printf("Enter number of prerequisites: ");
    scanf("%d", &prerequisitesSize);

    int** prerequisites = malloc(prerequisitesSize * sizeof(int*));

    for (int i = 0; i < prerequisitesSize; i++) {

        prerequisites[i] = malloc(2 * sizeof(int));

        printf("Enter prerequisite pair %d: ", i + 1);
        scanf("%d %d",
              &prerequisites[i][0],
              &prerequisites[i][1]);
    }

    if (canFinish(numCourses, prerequisites, prerequisitesSize))
        printf("true\n");
    else
        printf("false\n");

    // Free prerequisites
    for (int i = 0; i < prerequisitesSize; i++)
        free(prerequisites[i]);

    free(prerequisites);

    return 0;
}