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
vector<vector<int>> tplt;

void dfs(int u,vector<int> &v){
    visited[u]=true;
    v.push_back(u); // lưu đỉnh liên thông vào vector v
    for(int x:adj[u]){
        if(!visited[x]){
            dfs(x,v);
        }
    }
    
}

int main(){
    faster;
    cin>>n;
    for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
		}
	}
    for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(a[i][j]){
                adj[i].push_back(j);
                adj[j].push_back(i); // nếu đồ thị có hướng thì không có push x vào y
            }
		}
	}

    int cnt=0;
    for(int i=1;i<=n;++i){
        if(!visited[i]){
            
            vector<int> v;
            dfs(i,v);
            ++cnt;
            sort(v.begin(),v.end()); // sắp xếp các đỉnh liên thông
            tplt.push_back(v); // lưu các đỉnh liên thông vào tplt

            
        }
    }
    cout<<cnt<<endl;
    for(auto it:tplt){
        for(int x:it){
            cout<<x<<" ";
        }
        cout<<endl;
    }


}