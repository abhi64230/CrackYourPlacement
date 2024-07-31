#include<iostream>
#include<vector>
using namespace std;

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        vector<long long int> result(n, 1);
        long long int left = 1, right = 1;

        // Calculate left products
        for (int i = 1; i < n; i++) {
            result[i] = result[i - 1] * nums[i - 1];
        }

        // Calculate right products and combine with left products
        for (int i = n - 2; i >= 0; i--) {
            right *= nums[i + 1];
            result[i] *= right;
        }

        return result;       
    }
};

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
  vector<long long int> P(n, 1); 

    for (int i = 0; i < n; ++i) {
        long long int product = 1;
        
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                product *= nums[j];
            }
        }
        P[i] = product;
    }

    return P;

    }
    };