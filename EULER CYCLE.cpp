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
set<int> adj[1001];
int degree[1001];

void nhap(){
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int x,y;
        cin>>x>>y;
        adj[x].insert(y);
        adj[y].insert(x);
        degree[x]++;
        degree[y]++;
    }
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
    nhap();
    euler(1);

}