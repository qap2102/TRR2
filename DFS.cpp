#include <bits/stdc++.h>
using namespace std;
#define faster                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long
#define fi first
#define se second
const int MOD = 1e9+7;
const int N=1e6+5;


int n,m;
vector<int> adj[1001];
bool visited[1001];

void in(){
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x); // nếu đồ thị có hướng thì không có push x vào y
    }
    memset(visited,false,sizeof(visited));
}

void dfs(int u){
    cout<<u<<" ";
    visited[u]=true;
    for(int v:adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}

int main(){
    faster;
    in();
    dfs(1);
}




