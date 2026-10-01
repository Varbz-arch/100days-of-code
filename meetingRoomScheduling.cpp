// Problem: Given meeting intervals, find minimum number of rooms required.
// Sort by start time and use min-heap on end times.

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int minMeetingRooms(vector<vector<int>>& meetings) {

    // Step 1: Sort by start time
    sort(meetings.begin(), meetings.end());

    // Min-heap: stores end times
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int maxRooms = 0;

    for (auto meeting : meetings) {

        int start = meeting[0];
        int end = meeting[1];

        // If earliest meeting has ended,
        // its room can be reused
        if (!minHeap.empty() && start >= minHeap.top()) {
            minHeap.pop();
        }

        // Add current meeting's end time
        minHeap.push(end);

        // Maximum rooms needed
        maxRooms = max(maxRooms, (int)minHeap.size());
    }

    return maxRooms;
}

int main() {

    vector<vector<int>> meetings = {
        {0, 30},
        {5, 10},
        {15, 20}
    };

    cout << "Minimum rooms required: "
         << minMeetingRooms(meetings);

    return 0;
}