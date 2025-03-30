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


// chuyển danh sách cạnh sang danh danh sách kề
int n, m;
vector<int> adj[1001];
// adj lưu danh sách kề của đỉnh i
int main(){
	faster;
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i=1;i<=n;++i){
		cout<<i<<" : ";
		for(int k:adj[i]){
			cout<<k<<" ";
		}
		cout<<endl;
	}

	
}



