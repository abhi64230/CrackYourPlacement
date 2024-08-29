#include<iostream>
#include<vector>
using namespace std;


class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    // int orangesRotting(vector<vector<int>>& grid) {
    //     // Code here
    // }
    struct node
    {
        int i,j,time;
        node(int x, int y, int z):i(x),j(y),time(z)
        {}
    };
    int orangesRotting(vector<vector<int>>& grid) {
        queue<node> q;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[i].size();++j)
            {
                if(grid[i][j]==2)
                {
                    node n(i,j,0);
                    q.push(n);
                }
            }
        }
        int minTime=0;
        vector<vector<int>> visi(grid.size(),vector<int>(grid[0].size(),0));
        while(!q.empty())
        {
            node front = q.front();
            q.pop();
            minTime=max(minTime,front.time);
            visi[front.i][front.j]=1;
            if(front.i-1>=0 && grid[front.i-1][front.j]==1 && !visi[front.i-1][front.j])
            {
                node n(front.i-1,front.j,front.time+1);
                q.push(n);
                // cout<<"i="<<n.i<<"j="<<n.j<<"time="<<n.time<<endl;
                grid[n.i][n.j]=2;
            }
            if(front.j+1<grid[0].size() && grid[front.i][front.j+1]==1 && !visi[front.i][front.j+1])
            {
                node n(front.i,front.j+1,front.time+1);
                q.push(n);
                // cout<<"i="<<n.i<<"j="<<n.j<<"time="<<n.time<<endl;
                grid[n.i][n.j]=2;
            }
            if(front.i+1<grid.size() && grid[front.i+1][front.j]==1 && !visi[front.i+1][front.j])
            {
                node n(front.i+1,front.j,front.time+1);
                q.push(n);
                // cout<<"i="<<n.i<<"j="<<n.j<<"time="<<n.time<<endl;
                grid[n.i][n.j]=2;
            }
            if(front.j-1 >= 0 && grid[front.i][front.j-1]==1 && !visi[front.i][front.j-1])
            {
                node n(front.i,front.j-1,front.time+1);
                q.push(n);
                // cout<<"i="<<n.i<<"j="<<n.j<<"time="<<n.time<<endl;
                grid[n.i][n.j]=2;
            }
        }
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[i].size();++j)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return minTime;
    }
};
