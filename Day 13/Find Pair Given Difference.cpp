#include<iostream>
#include<vector>
using namespace std;


class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
         sort(arr.begin(), arr.end()); // Step 1: Sort the array
        int left = 0;
        int right = 1;

        // Step 2: Use two pointers to find the pair
        while (right < n) {
            int diff = arr[right] - arr[left];
            if (diff == x) {
                return 1;
            } else if (diff < x) {
                right++;
            } else {
                left++;
                if (left == right) { // Ensure right is always ahead of left
                    right++;
                }
            }
        }
        return -1; 
    }
};