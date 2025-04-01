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
int a[1001][1001];
bool visited[1001];
vector<int> adj[1001];

vector<int> dinhthat;

vector<pair<int,int>> vp;
vector<pair<int,int>> check;

void nhap(){
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        vp.push_back({x,y});
    }
}

void dfs(int u, int p){
    if(u==p) return;
    visited[u]=true;
    for(int v:adj[u]){
        if(!visited[v]){
            dfs(v,p);
        }
    }
}

int main(){
    faster;
    int n,m,u,v;
    cin>>n>>m>>u>>v;
    for(int i=0;i<m;++i){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        vp.push_back({x,y});
    }
    for(int i=1;i<=n;++i){
        if(i==u||i==v) continue;
        memset(visited, 0, sizeof(visited));
        dfs(u,i);
        if(!visited[v]){
            dinhthat.push_back(i);
        }
    }
    cout<<dinhthat.size()<<endl;
    for(auto it:dinhthat){
        cout<<it<<" ";
    }

}

