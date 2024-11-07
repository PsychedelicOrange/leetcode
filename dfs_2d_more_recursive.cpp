#include <iostream>
#include <vector>
using namespace std;
vector<vector<bool>> visited;
vector<vector<int>> grid;
void dfs(int* v,int* count)
{
    visited[v[0]][v[1]] = true;
    if(grid[v[0]][v[1]])
        (*count)++;
    else
        return;
    int temp[4][2]={v[0]+1,v[1],
                    v[0]-1,v[1],
                    v[0],v[1]+1,
                    v[0],v[1]-1};
    for(int i= 0; i< 4;i++)
    {
        bool inbounds =( temp[i][0] < grid.size() ) && temp[i][0] >= 0;
        inbounds &= ( temp[i][1] < grid[0].size() ) && temp[i][1] >= 0;
        if(inbounds && !visited[temp[i][0]][temp[i][1]])
            dfs(temp[i],count);
    }
}
int main()
{
    int gridd[][13] = {0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,1,0,0,0,1,0,0,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0};
    
    for(int j =0 ; j < 8;j++)
    {
    vector<int> temp;
        for(int i=0;i<13;i++)
        {
            temp.push_back(gridd[j][i]);
        }
    grid.push_back(temp);
    } 
    visited = vector<vector<bool>>(grid.size(),vector<bool>(grid[0].size()));
    int max = 0 ;
    for(int i=0;i<grid.size();i++)
    {
        for(int j = 0 ; j<grid[0].size();j++)
        {
            if(!visited[i][j] && grid[i][j] == 1)
            {
                int v[2] = {i,j};
                int* count = new int(0);
                dfs(v,count);
                if(*count>max)
                    max = *count;
                cout<<i<<","<<j<<" c: "<<*count<<endl;
            }
        }   
        
    }
    cout<< max << " is the largest island !";
}