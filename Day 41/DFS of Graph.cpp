#include<iostream>
#include<vector>
using namespace std;


class Solution {
  
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> dfsList;
        vector<int> vis(V, 0);
        stack<int> st;
        
        st.push(0);
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                dfsList.push_back(node);
            }
            vis[node] = 1;
            
            for(int i = (adj[node].size())-1; i>=0; i--){
                if(!vis[adj[node][i]]){
                    st.push(adj[node][i]);
                }
            }
        }
        return dfsList;
    }
};
