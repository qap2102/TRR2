#include <bits/stdc++.h>
using namespace std;
#define faster                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long



int main(){
    faster;
    int t;
	cin>>t;
    int n;
	cin>>n;
	int a[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}	
	}
    if(t==2){	    
		
		int b[n];
		for(int i=0;i<n;i++){
			int count=0;
			for(int j=0;j<n;j++){
				if(a[i][j]){
					count++;
				}
			}
			b[i]=count;
		}
		for(int i=0;i<n;i++){
			cout<<b[i]<<" ";
			for(int j=0;j<n;j++){
				if(a[i][j]==1)	cout<<j+1<<" ";
			}	
			cout<<endl;
		}
	}
	else{
		for(int i=0;i<n;i++){
			int count=0;
			for(int j=0;j<n;j++){
				if(a[i][j]){
					count++;
				}
			}
			cout<<count<<" ";
		}
	}
}
