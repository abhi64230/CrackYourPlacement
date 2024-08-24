#include<iostream>
#include<vector>
using namespace std;

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        
         map<string,vector<string>>m;
        int n=string_list.size();
        
        for(int i=0;i<n;i++){
            string s=string_list[i];
            sort(s.begin(),s.end());
            m[s].push_back(string_list[i]);
        }
        
        vector<vector<string>>ans;
        
        for(auto i:m){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};

