// Problem: Given intervals, merge all overlapping ones.
// Sort first, then compare with previous.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty())
        return {};

    // Sort by starting time
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;

    // Add first interval
    result.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {

        // If overlapping
        if (intervals[i][0] <= result.back()[1]) {
            // Merge
            result.back()[1] = max(result.back()[1], intervals[i][1]);
        }
        else {
            // No overlap
            result.push_back(intervals[i]);
        }
    }

    return result;
}

int main() {
    vector<vector<int>> intervals = {
        {1, 3},
        {2, 6},
        {8, 10},
        {9, 12}
    };

    vector<vector<int>> result = mergeIntervals(intervals);

    for (auto interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    return 0;
}