#include<iostream>
#include<vector>
using namespace std;



class Solution {
public:
    int slidingWindow(string &s, int k, char &ch)
    {
        int n = s.size(); // Get the size of the string
        int mx = 0; // Variable to store the maximum length of the substring found
        int i = 0, j = 0; // Initialize two pointers for the sliding window
        
        // Expand the window by moving the right pointer (j)
        while(j < n)
        {
            // If the current character is not the target character (ch)
            if(s[j++] != ch) 
                k--; // Decrease the count of available replacements
            
            // If the number of replacements exceeds k, shrink the window from the left
            while(k < 0)
                // Move the left pointer (i) to the right
                if(s[i++] != ch) 
                    k++; // If the character at the left pointer is not the target character, increase k (restore a replacement)
            
            // Update the maximum length found
            mx = max(mx, j - i); // Update mx with the current length of the valid window
        }
        return mx; // Return the maximum length found
    }
    
    // Function to find the maximum length of a substring that can be formed with at most k replacements
    int characterReplacement(string s, int k) 
    {
        int ans = 0; // Variable to store the final answer (maximum length found)
        
        // Iterate over each character from 'A' to 'Z'
        for(char ch = 'A'; ch <= 'Z'; ch++)
        {
            // Call the slidingWindow function for each character and update the answer
            int mx = slidingWindow(s, k, ch);
            ans = max(ans, mx); // Update the overall maximum length
        }
        
        return ans; // Return the final answer
    }
};