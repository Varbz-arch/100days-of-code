// Given two arrays start[] and end[] such that start[i] is the starting time of ith meeting and end[i] is the ending time of ith meeting. 
// Return the minimum number of rooms required to attend all meetings.

// Note: A person can also attend a meeting if it's starting time is same as the previous meeting's ending time.

// Examples:

// Input: start[] = [1, 10, 7], end[] = [4, 15, 10]
// Output: 1
// Explanation: Since all the meetings are held at different times, it is possible to attend all the meetings in a single room.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minMeetingRooms(vector<int> &start, vector<int> &end) {
    int n = start.size();

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int i = 0;
    int j = 0;

    int rooms = 0;
    int maxRooms = 0;

    while (i < n) {

        // New meeting starts before the previous meeting ends
        if (start[i] < end[j]) {
            rooms++;
            maxRooms = max(maxRooms, rooms);
            i++;
        }
        else {
            // Meeting ended, so we can reuse its room
            rooms--;
            j++;
        }
    }

    return maxRooms;
}

int main() {
    vector<int> start = {1, 10, 7};
    vector<int> end = {4, 15, 10};

    cout << "Minimum rooms required: "
         << minMeetingRooms(start, end);

    return 0;
}