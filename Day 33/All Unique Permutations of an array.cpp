#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        set<vector<int>> s;
        s.insert(arr);
        while(next_permutation(arr.begin(),arr.end()))
        {
            s.insert(arr);
        }
        
        for(auto x : s)
        {
            ans.push_back(x);
        }
        return ans;
    }
};
