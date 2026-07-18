#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;
    cin >> n>> m ;
    // int adji[n+1][m+1];

    // for(int i=0;i<m;i++){
    //     int u,v;
    //     cin>>u>>v;
    //     adji[u][v]='1';
    //     adji[v][u]='1';
    // }

    //another list method:
vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
        return 0;

}