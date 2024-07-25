#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    
    sort(a.begin(),a.end());
    int i =0;
    int j = m-1;
    int  ans = INT_MAX;
    while(j<n){
        int dif=a[j]-a[i];
        if(dif<ans){
            ans=dif;
        }
        i++;
        j++;
    }
     return ans;
    } 

};