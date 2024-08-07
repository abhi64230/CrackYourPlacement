#include<iostream>
#include<vector>
using namespace std;


// burte froce sloution

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        //  int n = arr.size();
    for (int i = 1; i <= n + 1; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (arr[j] == i) {
                found = true;
                break;
            }
        }
        if (!found) {
            return i;
        }
    }
    return n + 1;
    } 
};


// better sloution

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) { 
    //  int n = arr.size();
    
    // Step 1: Segregate positive and non-positive numbers
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    
    // Step 2: Use the positive part of the array to mark presence
    for (int i = j; i < n; i++) {
        int val = abs(arr[i]);
        if (val - 1 < n - j && arr[val - 1 + j] > 0) {
            arr[val - 1 + j] = -arr[val - 1 + j];
        }
    }
    
    // Step 3: Find the first positive index which indicates the missing number
    for (int i = j; i < n; i++) {
        if (arr[i] > 0) {
            return i - j + 1;
        }
    }
    
    // If all indices are marked, then return n - j + 1
    return n - j + 1;   
     
        
    }
};