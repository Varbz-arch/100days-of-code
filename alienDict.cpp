// An alien language uses the lowercase English alphabet, but the order of its letters is unknown. You are given an array of strings words[] that is claimed to be sorted lexicographically according to the rules of the alien language.

// Determine the order of the letters in the alien alphabet.

// If a valid ordering exists, return a string containing all unique letters in lexicographical order according to the alien language.
// Otherwise, return an empty string.
// If a string s1 is lexicographically smaller than a string s2, and the first position at which they differ contains letter a in s1 and letter b in s2, then a must appear before b in the alien alphabet.

// Note: The driver code prints true if the returned order is valid; otherwise, it prints false.

// Examples:

// Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]
// Output: true
// Explanation: A possible correct order of letters in the alien dictionary is "bdac".
// The pair "baa" and "abcd" suggests 'b' appears before 'a' in the alien dictionary.
// The pair "abcd" and "abca" suggests 'd' appears before 'a' in the alien dictionary.
// The pair "abca" and "cab" suggests 'a' appears before 'c' in the alien dictionary.
// The pair "cab" and "cad" suggests 'b' appears before 'd' in the alien dictionary.
// So, 'b' -> 'd' -> 'a' -> 'c' is a valid ordering.

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

string findOrder(vector<string>& words) {
    vector<vector<int>> adj(26);
    vector<int> indegree(26, 0);
    vector<bool> present(26, false);

    // Find all unique characters
    for (string word : words) {
        for (char c : word) {
            present[c - 'a'] = true;
        }
    }

    // Build graph
    for (int i = 0; i < words.size() - 1; i++) {
        string s1 = words[i];
        string s2 = words[i + 1];

        int j = 0;

        // Find first different character
        while (j < s1.size() &&
               j < s2.size() &&
               s1[j] == s2[j]) {
            j++;
        }

        // Invalid case: longer word comes before its prefix
        if (j == s2.size() && s1.size() > s2.size()) {
            return "";
        }

        // Create edge
        if (j < s1.size() && j < s2.size()) {
            int u = s1[j] - 'a';
            int v = s2[j] - 'a';

            // Avoid duplicate edge
            bool exists = false;

            for (int x : adj[u]) {
                if (x == v) {
                    exists = true;
                    break;
                }
            }

            if (!exists) {
                adj[u].push_back(v);
                indegree[v]++;
            }
        }
    }

    // Kahn's Algorithm
    queue<int> q;

    for (int i = 0; i < 26; i++) {
        if (present[i] && indegree[i] == 0) {
            q.push(i);
        }
    }

    string ans = "";

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        ans += char(u + 'a');

        for (int v : adj[u]) {
            indegree[v]--;

            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // Check for cycle
    int totalCharacters = 0;

    for (int i = 0; i < 26; i++) {
        if (present[i]) {
            totalCharacters++;
        }
    }

    if (ans.size() != totalCharacters) {
        return "";
    }

    return ans;
}

int main() {

    vector<string> words = {
        "baa",
        "abcd",
        "abca",
        "cab",
        "cad"
    };

    string order = findOrder(words);

    if (order == "") {
        cout << "No valid ordering exists" << endl;
    } else {
        cout << "Alien Order: " << order << endl;
    }

    return 0;
}