#include<iostream>
#include<vector>
using namespace std;


class Solution {
  public:
    bool arraySortedOrNot(vector<int>& arr) {
          int n = arr.size(); // Get the size of the array
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }
};