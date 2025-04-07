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
 
set<int> adj[101];
int degree[101];
bool visited[101];
 
int n,m,u;


void dfs(int u){
    visited[u]=true;
    for(int i=1;i<=n;++i){
        if(!visited[i]){
            
            dfs(i);
        }
    }

}
bool kiemtra(){
    int ans=0;
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=n;++i){
        if(!visited[i]){
            ++ans;
            dfs(i);
        }
    }
    if(ans==1) return true;
    else return false;
}
 
 
void euler(int v){
    stack<int> st;
    vector<int> ec;
    st.push(v);
    while(!st.empty()){
        int x = st.top();
        if(adj[x].size()!=0){
            int y = *adj[x].begin();
            st.push(y);
            adj[x].erase(y);
            adj[y].erase(x);
 
        }
        else {
            st.pop();
            ec.push_back(x);
        }
    }
    reverse(ec.begin(),ec.end());
    for(int x:ec){
 
        cout<<x<<" ";
    }
}
 
 
 
int main(){
    faster;
    // freopen("CT.INP", "r", stdin);
	// freopen("CT.OUT", "w", stdout);
    adj-> clear();
    memset(degree,0,sizeof(degree));
    int t;
    cin>>t;
 
    if(t==1){
        cin>>n>>m;
        memset(degree,0,sizeof(degree));
        adj->clear();
        for(int i=1;i<=m;++i){
            int x,y;
            cin>>x>>y;
            adj[x].insert(y);
            adj[y].insert(x);
            degree[x]++;
            degree[y]++;
        }
        // int cnt=0;
        // int kt=0;
        // for(int i=1;i<=n;++i){
        //     if(degree[i]%2!=0){
        //         cnt++;
        //         kt=1;
        //     }
        // }
        // if(kt==0) cout<<"1"<<endl;
        // else if(cnt==2) cout<<"2"<<endl;
        // else cout<<"0"<<endl;
        
        if(kiemtra()){
            int cnt=0;
            int kt=0;
            for(int i=1;i<=n;++i){
                if(degree[i]%2!=0){
                    cnt++;
                    kt=1;
                }
            }
            if(kt==0) cout<<"1";
            else if(cnt==0||cnt==2) cout<<"2";
            else cout<<"0";
        }
        else cout<<"0";
 
 
 
    }
 
    else if(t==2){
        cin>>n>>m>>u;
        memset(degree,0,sizeof(degree));
        adj->clear();
        for(int i=1;i<=m;++i){
            int x,y;
            cin>>x>>y;
            adj[x].insert(y);
            adj[y].insert(x);
 
        }
        euler(u);
    }
 
 
 
 
}