// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
// You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first
//  if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. 
// If it is impossible to finish all courses, return an empty array.

 

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. 
// So the correct course order is [0,1].

#include <stdio.h>
#include <stdlib.h>

int main() {

    int numCourses, prerequisitesSize;

    printf("Enter number of courses: ");
    scanf("%d", &numCourses);

    printf("Enter number of prerequisites: ");
    scanf("%d", &prerequisitesSize);

    int prerequisites[prerequisitesSize][2];

    printf("Enter prerequisites (course prerequisite):\n");

    for (int i = 0; i < prerequisitesSize; i++) {
        scanf("%d %d", &prerequisites[i][0], &prerequisites[i][1]);
    }

    // Indegree of every course
    int indegree[numCourses];

    for (int i = 0; i < numCourses; i++) {
        indegree[i] = 0;
    }

    // Calculate indegree
    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];

        indegree[course]++;
    }

    // Queue
    int queue[numCourses];
    int front = 0;
    int rear = 0;

    // Add courses with no prerequisites
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Result
    int result[numCourses];
    int count = 0;

    // BFS
    while (front < rear) {

        int course = queue[front++];

        result[count++] = course;

        // Find courses depending on this course
        for (int i = 0; i < prerequisitesSize; i++) {

            int nextCourse = prerequisites[i][0];
            int prerequisite = prerequisites[i][1];

            if (prerequisite == course) {

                indegree[nextCourse]--;

                if (indegree[nextCourse] == 0) {
                    queue[rear++] = nextCourse;
                }
            }
        }
    }

    // Check for cycle
    if (count != numCourses) {
        printf("It is impossible to finish all courses.\n");
        return 0;
    }

    // Print ordering
    printf("Course order: ");

    for (int i = 0; i < numCourses; i++) {
        printf("%d ", result[i]);
    }

    printf("\n");

    return 0;
}