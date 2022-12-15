#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector< int >   vi;
typedef vector< vi >   mi;

// -----------------------------------------------------------------

const int NODES_N = 3e5 + 5e3;

mi adj;
bool vis[NODES_N];
int lvl[NODES_N], parent[NODES_N];
vi path;


void init(){
    for(int i = 0 ; i < NODES_N ; i++){
        vis[i] = 0;
        lvl[i] = -1;
        parent[i] = -1;
    }
}

void bfs(int start){

    /// ----- define how to calc the answer ----- ///
    init();

    /// ----- define the queue and add the root ----- ///
    queue<ii> q;

    ///  {idx,level}
    q.push({start,0});

    vis[start] = 1;
    lvl[start] = 0;
    parent[start] = -1;

    while(!q.empty()){

        /// ----- pop the element ----- ///
        ii x = q.front();q.pop();

        /// ----- push the children and proccess the answer ----- ///
        for(auto c : adj[x.first]){
            if(!vis[c]){
                q.push({c,x.second+1});
                vis[c] = 1;
                lvl[c] = x.second+1;
                parent[c] = x.first;
            }
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



