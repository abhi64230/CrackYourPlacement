#include<iostream>
#include<vector>
using namespace std;


class Solution {
    int check(int a[],int n,long long mid){
        int f = 1;
        int pages = 0;
        for(int i=0;i<n;i++){
            pages+=a[i];
            if(pages>mid){
                f++;
                pages = a[i];
            }
        }
        return f;
    }
  public:
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        // code here
        if(n<m) return -1;
        long long end = accumulate(arr,arr+n,0);
        long long start = *max_element(arr,arr+n);
        long long ans = end;
        while(start<=end){
            long long mid = start + (end-start)/2;
            int cnt = check(arr,n,mid);
            // cout<<"mid: "<<mid<<"cnt: "<<cnt<<endl;
            if(cnt>m){
                start = mid+1;
            }else{
                ans=mid;
                end=mid-1;
            }
        }
        return ans;
    }
};