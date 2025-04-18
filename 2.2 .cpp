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

int n,m,u,v;
int a[1001][1001];
bool visited[1001];
vector<int> adj[1001];
int parent[1001];

void dfs(int u){
    visited[u]=true;
    for(int v:adj[u]){
        if(!visited[v]){
            parent[v]=u; // lưu đỉnh cha của x là u
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
        q.pop();
        for(int k:adj[v]){
            if(!visited[k]){
                q.push(k);
                visited[k]=true;
                parent[k]=v; // lưu đỉnh cha của x là v
            }
        }
        
    }
}


void path(int u, int v){
    memset(visited,false,sizeof(visited));
    memset(parent,0,sizeof(parent));

    dfs(u);
    if(!visited[v]){
        cout<<0<<endl;
        return;
    }
    else {
        vector<int> path;
        while(v!=u){
            path.push_back(v);
            v=parent[v]; // đi từ v về u
        }
        path.push_back(u);
        reverse(path.begin(),path.end()); // đảo ngược vector path
        for(int k:path){
            cout<<k<<" ";
        }
    }
}

void path1(int u, int v){
    memset(visited,false,sizeof(visited));
    memset(parent,0,sizeof(parent));
    
    bfs(u);
    if(!visited[v]){
        cout<<0<<endl;
        return;
    }
    else {
        vector<int> path;
        while(v!=u){
            path.push_back(v);
            v=parent[v]; // đi từ v về u
        }
        path.push_back(u);
        reverse(path.begin(),path.end()); // đảo ngược vector path
        for(int k:path){
            cout<<k<<" ";
        }
    }
}

int main(){
    faster;
    freopen("TK.INP", "r", stdin);
	freopen("TK.OUT", "w", stdout);
    int t;
    cin>>t;
    cin>>n>>m>>u>>v;
    for(int i=0;i<m;++i){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
    if(t==1){
        int cnt=0;
        for(int i:adj[u]){
            for(int j:adj[i]){
                if(j==v) cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    else if(t==2){
        path(u,v);
    }
    for(int i=0;i<101;i++) adj[i].clear();
}