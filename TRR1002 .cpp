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
vector<int> adj[1001];
vector<int> b;


int main(){
    faster;
    ifstream fin("DT.INP");
	ofstream fout("DT.OUT");
    int t;
    fin>>t;
    int n;
    fin>>n;
    for(int i=1;i<=n;++i){
        int cnt=0;
        for(int j=1;j<=n;++j){
            fin>>a[i][j];
            if(a[i][j]){
                ++cnt;
            }
        }
        b.push_back(cnt);

    }
    if(t==1){
        
        for(auto it:b){
            fout<<it<<" ";
        }
    }
    else {
        fout<<n<<endl;
        int c[n];
        for(int i=1;i<=n;++i){
            int cnt=0;
            for(int j=1;j<=n;++j){
                if(a[i][j]){
                    ++cnt;
                    adj[i].push_back(j);
                }
            }
            c[i]=cnt;
        }
        for(int i=1;i<=n;++i){
            fout<<c[i]<<" ";
            for(auto k:adj[i]){
                fout<<k<<" ";
            }
            fout<<endl;
        }
    }
    b.clear();
    for(int i=1;i<=1001;++i){
        adj[i].clear();
    }
    fin.close();
	fout.close();

}