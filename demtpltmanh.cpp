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

int main(){
    faster;
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
}