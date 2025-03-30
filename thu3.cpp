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


// chuyển ma trận kề sang danh sách cạnh
int n, m;
vector<int> adj[1001];
int a[1001][1001];
vector<pair<int,int>> vp;
// adj lưu danh sách kề của đỉnh i
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
			if(a[i][j]==1&&i<j){
				vp.push_back({i,j});
				
			}
		}
	}
	for(auto it:vp){
		cout<<it.fi<<" "<<it.se<<endl;
	}

	
}



