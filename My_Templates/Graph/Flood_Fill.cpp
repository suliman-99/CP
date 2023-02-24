#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int>     ii;
typedef vector< int >   vi;
typedef vector< ii >   vii;

// -----------------------------------------------------------------


// ///  ----- {S,  E,  N,  W}
// int dr[] = {1,  0, -1,  0};
// int dc[] = {0,  1,  0, -1};
// int d_size = 4;

///  ----- {S, SE, E, NE,  N, NW,  W, SW}
int dr[] = {1,  1, 0, -1, -1, -1,  0,  1};
int dc[] = {0,  1, 1,  1,  0, -1, -1, -1};
int d_size = 8;

const int GRID_N = 1005;

char grid[GRID_N][GRID_N];
bool vis[GRID_N][GRID_N];
int parent_move[GRID_N][GRID_N], lvl[GRID_N][GRID_N];
vi moves_path;
vii points_path;

int rows_n, cols_n;

bool is_valid(int r, int c,char valid){
    return (0 <= r && r < rows_n && 0 <= c && c < cols_n && grid[r][c] == valid);
}


void init(){
    for(int i = 0 ; i < rows_n ; i++){
        for(int j = 0 ; j < cols_n ; j++){
            vis[i][j] = 0;
            lvl[i][j] = -1;
            parent_move[i][j] = -1;
        }
    }
}

/// put (visited) like (valid) if no need to change the value in the grid
int flood_fill(int r,int c,char valid,char visited,int l){
    int ans = 1;
	for(int d = 0 ; d < d_size ; d ++){
        int nr = r+dr[d], nc = c+dc[d];
		if(is_valid(nr,nc,valid) && !vis[nr][nc]){
            vis[nr][nc] = 1;
            lvl[nr][nc] = l;
            parent_move[nr][nc] = d;
            grid[nr][nc] = visited;
			ans += flood_fill(r+dr[d],c+dc[c],valid,visited,l+1);
		}
	}
    return ans;
}


 
void get_moves_path(int end_r,int end_c){
    moves_path.clear();
    if(!vis[end_r][end_c]){
        moves_path.push_back(-1);
        return;
    }
    while(end_r != -1 && end_c != -1){
        moves_path.push_back(parent_move[end_r][end_c]);
        end_r -= dr[parent_move[end_r][end_c]];
        end_c -= dc[parent_move[end_r][end_c]];
    }
    reverse(moves_path.begin(),moves_path.end());
}
 
void get_points_path(int end_r,int end_c){
    points_path.clear();
    if(!vis[end_r][end_c]){
        points_path.push_back({-1,-1});
        return;
    }
    while(end_r != -1 && end_c != -1){
        points_path.push_back({end_r,end_c});
        end_r -= dr[parent_move[end_r][end_c]];
        end_c -= dc[parent_move[end_r][end_c]];
    }
    reverse(points_path.begin(),points_path.end());
}


