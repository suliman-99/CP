#include <bits/stdc++.h>
using namespace std;

typedef long long       ll;
typedef unsigned long long       ull;
typedef vector<int>       vi;
typedef vector<vi>        mi;

// -----------------------------------------------------------------

int log2_floor(ull i){ return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1; }

// build in O(nlogn) - get in O(1) - no update
class SparseTableIdx{
	private:
		mi st;
        ll* arr;

        // min, max, ...
        int _conquer(int idx1, int idx2){ 
			if(arr[idx1] < arr[idx2]) return idx1; // min
			// if(arr[idx1] > arr[idx2]) return idx1; // max
			else return idx2;	
		}
		
	public:
		void build(int sz, ll arr[]){
            st.assign(log2_floor(sz)+1, vi(sz));
            this->arr = arr;
			for(int i = 0 ; i < st[0].size() ; i++) st[0][i] = i;
			for(int j = 1 ; j < st.size() ; j++)
				for(int i = 0 ; i < st[j].size() ; i++)
					st[j][i] = _conquer(st[j-1][i], st[j-1][i+(1<<(j-1))]);
		}
		
		int get(int i ,int j){
			int k = log2_floor(j-i+1);
			return _conquer(st[k][i], st[k][j-(1<<k)+1]);
		}
};