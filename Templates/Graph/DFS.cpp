#include <bits/stdc++.h>
using namespace std;

typedef vector< int >   vi;
typedef vector< vi >   mi;

// -----------------------------------------------------------------

const int NODES_N = 3e5 + 5e3;

mi adj;
bool vis[NODES_N];
int parent[NODES_N], lvl[NODES_N];
vi path;


void init(){
    for(int i = 0 ; i < NODES_N ; i++){
        vis[i] = 0;
        parent[i] = -1;
        lvl[i] = -1;
    }
}


void dfs(int i,int l){
	for(auto c : adj[i]){
		if(!vis[c]){
			vis[c] = 1;
			parent[c] = i;
			lvl[c] = l+1;
			dfs(c,l+1);
		}
	}
}


void dfs_all(){
	init();
	for(int i = 1 ; i < adj.size() ; i++){
		if(!vis[i]){
			vis[i] = 1;
			parent[i] = -1;
			lvl[i] = 0;
			dfs(i,0);
		}
	}
}
 
void get_path(int end){
    path.clear();
    if(!vis[end]){
        path.push_back(-1);
        return;
    }
    while(end != -1){
        path.push_back(end);
        end = parent[end];
    }
    reverse(path.begin(),path.end());
}
