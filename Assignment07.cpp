#include<bits/stdc++.h>
using namespace std;

int minimumedge(vector<int>& wt,vector<bool>& visited)
{
    int minimum = INT_MAX;
    int min;
    
    for(int i = 0 ; i < wt.size() ; i++)
    {
        if(wt[i] < minimum && visited[i] == false)
            minimum=wt[i], min = i;
    }
    return min;
}

void prim(vector<vector<int>>& mat)
{
    vector<int> ans(mat.size());
    vector<int> wt(mat.size(),1e9);
    vector<bool> visited(mat.size(),false);
    
    wt[0] = 0;
    ans[0] = -1;
    
    for(int count = 0 ; count < mat.size()-1 ; count++)
    {
        int edge = minimumedge(wt,visited);
        visited[edge] = true;
        
        for(int v = 0 ; v < mat.size() ; v++)
        {
            if(mat[edge][v] && !visited[v] && mat[edge][v] < wt[v])
            {
                ans[v] = edge;
                wt[v] = mat[edge][v];
            }
        }
    }
    //Printing MST
    for(int i = 1 ; i < mat.size() ; i++)
    {
        cout<<ans[i]<<"<-->"<<i<<" : "<<mat[i][ans[i]]<<endl;
    }
}

int main()
{
    int vertices;
    cout<<"Enter the Number Of Vertices : ";cin>>vertices;

    vector<vector<int>> mat(vertices,vector<int>(vertices,0));
    int op = 0;
    while(op != -1)
    {
        int i , j , weight;
        cout<<"Edge 1 =";cin>>i;
        cout<<"Edge 2 =";cin>>j;
        cout<<"Weight =";cin>>weight;
        mat[i][j] = weight;
        mat[j][i] = weight;
        cout<<"Press -1 to stop :";cin>>op;
    }
    prim(mat);
}
