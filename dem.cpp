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

void dfs(int u){
    cout<<u<<" ";
    visited[u]=true;
    for(int v:adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}


void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u]=true;
    while(!q.empty()){
        int v=q.front();
        cout<<v<<" ";
        for(int k:adj[v]){
            if(!visited[k]){
                q.push(k);
                visited[k]=true;
                
            }
        }
    }
}
void demlienthong(){
    int cnt=0;
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=n;++i){
        if(!visited[i]){
            ++cnt;
            dfs(i);
            // bfs(i);
            
        }
    }
    cout<<cnt<<endl;
}

int main(){
    faster;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x); // nếu đồ thị có hướng thì không có push x vào y
    }
    demlienthong();
}




