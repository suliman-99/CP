#include <bits/stdc++.h>
using namespace std;

typedef vector< int >   vi;
typedef vector< vi >   mi;

// -----------------------------------------------------------------

const int NODES_N = 3e5 + 5e3;

mi adj, components;
bool vis[NODES_N];
int components_n, parent[NODES_N], lvl[NODES_N];


void init(){
    components_n = 0;
    components.clear();
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
            components[components_n].push_back(i);
			dfs(c,l+1);
		}
	}
}


void find_connected_components(){
    init();
	for(int i = 1 ; i < adj.size() ; i++){
		if(!vis[i]){
            vis[i] = 1;
            parent[i] = -1;
            lvl[i] = 0;
            components.push_back(vi());
            components[components_n].push_back(i);
			dfs(i,0);
            components_n++;
		}
	}
}





