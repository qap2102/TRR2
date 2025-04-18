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

const int MAXN=105;

int t,n,m,u, start, endd;
int a[MAXN][MAXN];
// vector<int> adj[MAXN];
set<int> adj[MAXN];
vector<pair<int,int>> vp;
bool visited[MAXN];
int parent[MAXN];
vector<vector<int>> tplt;

bool kt = false;

void dfs(int u){
    stack<int> st;
    st.push(u);
    visited[u] = true;
    while(!st.empty()){
        int v = st.top();
        st.pop();
        for(int k:adj[v]){
            if(!visited[k]){
                visited[k] = true;
                parent[k] = v;
                st.push(k);
            }
            else if(k != parent[v]){
                kt = true;
                start = k;
                endd = v;
                return;
            }
        }
    }
}

int main(){
    faster;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=m;++i){
            int x,y;
            cin>>x>>y;
            adj[x].insert(y);
            adj[y].insert(x);
        }
        memset(visited,false,sizeof(visited));
        memset(parent,0,sizeof(parent));
        kt = false;
        vector<int> v1;
        
        
        for(int i=1;i<=n;++i){
            adj[i].clear();
        }


    }
}