#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
      int n = arr.size();
        unordered_map<int, int> mpp;
        int cnt = 0;
        int preSum = 0;
        mpp[0] = 1;
        for (int i = 0; i < n; i++) {
            preSum = (preSum + arr[i]) % k;
            if (preSum < 0) preSum += k;  // Ensure the remainder is positive
            if (mpp.find(preSum) != mpp.end()) {
                cnt += mpp[preSum];
            }
            mpp[preSum]++;
        }
        return cnt;
    }
};