#include <bits/stdc++.h>
using namespace std;

typedef vector< int >   vi;
typedef vector< vi >   mi;

// -----------------------------------------------------------------

const int NODES_N = 3e5 + 5e3;

mi adj;
bool vis[NODES_N];
vi sorted_v;

void init(){
    sorted_v.clear();
    for(int i = 0 ; i < NODES_N ; i++){
        vis[i] = 0;
    }
}


void topo_sort(int i){
	for(auto c : adj[i]){
		if(!vis[c]){
			vis[c] = 1;
			topo_sort(c);
		}
	}
    sorted_v.push_back(i);
}


void topo_sort_all(){
    init();
	for(int i = 1 ; i < adj.size() ; i++){
		if(!vis[i]){
			vis[i] = 1;
			topo_sort(i);
		}
	}
    reverse(sorted_v.begin(),sorted_v.end());
}
