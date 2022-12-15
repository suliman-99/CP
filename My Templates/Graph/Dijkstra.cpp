#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int>       vi;
typedef vector< ii >    vii;
typedef vector< vii >   mii;
typedef long long       ll;

// -----------------------------------------------------------------

struct node{
    int weight;
    int idx;
    int parent;
    int lvl;
};



const int NODES_N = 3e5 + 5e3;

mii adj;
bool vis[NODES_N];
ll dist[NODES_N];
int parent[NODES_N], lvl[NODES_N];
vi path;

void init(){
    for(int i = 0 ; i < NODES_N ; i++){
        vis[i] = 0;
        dist[i] = -1;
        parent[i] = -1;
        lvl[i] = -1;
    }
}

void dijkstra(int start){

    /// ----- define how to calc the answer ----- ///
    init();


    /// ----- define the priority_queue and add the root ----- ///
    priority_queue<node,vector<node>,greater<node>> q;
    
    ///  {{weight,idx},{parent,level}}
    q.push({0,start,-1,0});
    while(!q.empty()){

        /// ----- pop the element and proccess the answer ----- ///
        node x = q.top();q.pop();
        if(vis[x.idx]) continue;
        vis[x.idx] = 1;
        dist[x.idx] = x.weight;
        parent[x.idx] = x.parent;
        lvl[x.idx] = x.lvl;

        /// ----- push the children ----- ///
        for(auto c : adj[x.idx]){
            q.push({x.weight+c.second,c.first,x.idx,x.lvl+1});
        }
    }
}
 
void get_path(int f){
    path.clear();
    if(!vis[f]){
        path.push_back(-1);
        return;
    }
    while(f != -1){
        path.push_back(f);
        f = parent[f];
    }
    reverse(path.begin(),path.end());
}


