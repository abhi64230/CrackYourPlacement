#include<iostream>
#include<vector>
using namespace std;


class Solution {
  public:
    bool isPossible(int k, vector<int> &arr1, vector<int> &arr2) {
       sort(arr1.begin(), arr1.end()); // Sort arr1 in ascending order
        sort(arr2.begin(), arr2.end(), greater<int>()); // Sort arr2 in descending order

        for (int i = 0; i < arr1.size(); i++) {
            if (arr1[i] + arr2[i] < k) {
                return false;
            }
        }
        return true;
    }
};