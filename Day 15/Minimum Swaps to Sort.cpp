#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n = nums.size();
    vector<pair<int, int>> arrPos(n);
    for (int i = 0; i < n; ++i) {
        arrPos[i] = {nums[i], i};
    }

    // Sort the array by array value
    sort(arrPos.begin(), arrPos.end());

    // To keep track of visited elements
    vector<bool> visited(n, false);

    // Initialize result
    int swaps = 0;

    for (int i = 0; i < n; ++i) {
        // Already visited or already in the correct place
        if (visited[i] || arrPos[i].second == i)
            continue;

        // Find out the number of nodes in this cycle
        int cycle_size = 0;
        int j = i;
        while (!visited[j]) {
            visited[j] = true;
            j = arrPos[j].second;
            cycle_size++;
        }

        // Update the number of swaps required for this cycle
        if (cycle_size > 1) {
            swaps += (cycle_size - 1);
        }
    }

    return swaps;
	}
};
