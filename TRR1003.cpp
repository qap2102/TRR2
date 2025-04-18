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
 
int a[1001][1001];
int c[1001][1001];
vector<int> adj[1001];
vector<int> b;
vector<pair<int,int>> vp;
 
 
int main(){
    faster;
    freopen("DT.INP", "r", stdin);
	freopen("DT.OUT", "w", stdout);
	int t;
	cin>>t;
	int n;
	cin>>n;
	b.clear();
 
	for(int i=1;i<=n;++i){
		int cnt=0;
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
			if(a[i][j]){
				++cnt;
				if(i<j){
 
 
					vp.push_back({i,j});
				}
			}
		}
		b.push_back(cnt);
	}
	if(t==1){
		for(auto k : b){
			cout<<k<<" ";
		}
	}
	else if(t==2){
		// int c[1001][1001]={0};
		int m = vp.size();
		cout<<n<<" "<<m<<endl;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				c[i][j]=0;
			}
		}
		// for(int i=1;i<=m;++i){
		// 	c[vp[i].fi][i]=1;
		// 	c[vp[i].se][i]=1;
		// }
		for(int j=1;j<=m;++j){
			c[vp[j-1].fi][j]=1;
			c[vp[j-1].se][j]=1;
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				cout<<c[i][j]<<" ";
			}
			cout<<endl;
		}
		vp.clear();
 
	}
 
}