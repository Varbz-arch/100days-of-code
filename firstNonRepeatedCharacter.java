// Problem Statement
// Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

// Input Format
// A single string s.

// Output Format
// Print the first non-repeating character or '$' if none exists.

// Sample Input
// geeksforgeeks

// Sample Output
// f

// Explanation
// The character 'f' occurs only once in the string and appears before any other non-repeating character.

import java.util.*;

public class firstNonRepeatedCharacter {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.next();

        int[] freq = new int[26];

        // Count frequency
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        // Find first non-repeating character
        for (char c : s.toCharArray()) {
            if (freq[c - 'a'] == 1) {
                System.out.println(c);
                return;
            }
        }

        // If all characters repeat
        System.out.println('$');
    }
}