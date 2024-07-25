#include<iostream>
#include<vector>
using namespace std;

// burte force code 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         int n = nums.size(); 
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[i] + nums[j] == target){
                    return {i, j};
                }
            }
        }
        return {}; 
    }
};

// optimal

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>num_index;
        for(int i=0;i<nums.size();i++){
            num_index.push_back({nums[i],i});
        }
        sort(num_index.begin(), num_index.end());
        int left =0;
        int right =num_index.size()-1;
        while(left < right ){
            int sum = num_index[left].first+num_index[right].first;
            if(sum== target){
                return{num_index[left].second,num_index[right].second};}

                else if(sum<target){
                    left++;
                }
                else{
                    right--;
                }
            }
            return {};
        }
        

         
};