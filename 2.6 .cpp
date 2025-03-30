#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
int n, cnt;
vector<int> a[MAXN];//danh sÃ¡ch ká»
int tin[MAXN], low[MAXN];//thá»i gian Ä‘áº§u tiÃªn cáº­p nháº­t Ä‘á»‰nh trá»¥ vÃ  giÃ¡ trá»‹ tháº¥p nhÃ¡t cÃ³ thá»ƒ quay lui
bool visited[MAXN], check[MAXN];//Ä‘Ã¡nh dáº¥u Ä‘á»‰nh vÃ  Ä‘Ã¡nh dáº¥u Ä‘á»‰nh trá»¥
void DFS(int i, int cha){
	visited[i] = true;
	tin[i] = low[i] = cnt++;
	int con = 0;
	for(int x : a[i]){
		if(x == cha) continue;//bá» cáº¡nh quay láº¡i cha
		if(visited[x]){
			low[i] = min(low[i], tin[x]);//cáº­p nháº­t low náº¿u gáº·p cáº¡nh ngÆ°á»£c
		}
		else{
			DFS(x, i);
			low[i] = min(low[i], low[x]);
			if(low[x] >= tin[i] && cha != -1){
				check[i] = true;
			}
			con++;
		}
	}
	if(cha == -1 && con > 1) check[i] = true;
}
int main(){
	ifstream fin("TK.INP");
	ofstream fout("TK.OUT");
	fin >> n;
	for(int i=0; i<n; i++){
		int k, v; fin >> k;
		while(k--){
			fin >> v;
			a[i].push_back(v-1);
		}
	}
	fill(visited, visited+n, false);
	fill(check, check+n, false);
	cnt = 0;
	for(int i=0; i<n; i++){
		if(!visited[i]) DFS(i, -1);
	}
	vector<int> v;
	for(int i=0; i<n; i++){
		if(check[i]) v.push_back(i+1);
	}
	fout << v.size() << endl;
	if(!v.empty()){
		for(int it : v){
			fout << it << " ";
		}
		fout << endl;
	}
	fin.close();
	fout.close();
}