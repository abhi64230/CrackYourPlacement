#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& arr) {
          int element = 0;  // Candidate for majority element
        int count = 0;    // Counter for candidate

        // First pass: Find the candidate
        for (int i = 0; i < arr.size(); i++) {
            if (count == 0) {
                element = arr[i];  // Set new candidate
                count++;
            } else if (arr[i] == element) {
                count++;  // Same as candidate, increment count
            } else {
                count--;  // Different from candidate, decrement count
            }
        }

        int newCount = 0;

        // Second pass: Verify the candidate
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == element) {
                newCount++;  // Count occurrences of candidate
            }
        }

        // Check if candidate is the majority element
        if (newCount > arr.size() / 2) {
            return element;
        }

        return -1;  // No majority element
    }
};