#include <bits/stdc++.h>
using namespace std;

typedef long long       ll;
typedef unsigned long long       ull;
typedef vector< ll >    vll;
typedef vector< vll >   mll;

// -----------------------------------------------------------------

int log2_floor(ull i){ return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1; }

// build in O(nlogn) - get in O(1) - no update
class SparseTable{
	private:
		mll data;

        // min, max, or, and, gcd, ...
        ll _conquer(ll a1, ll a2){ return min(a1, a2); }

		void _build(ll arr[]){
			for(int i = 0 ; i < data[0].size() ; i++) data[0][i] = arr[i];
			for(int j = 1 ; j < data.size() ; j++)
				for(int i = 0 ; i < data[j].size() ; i++)
					data[j][i] = _conquer(data[j-1][i], data[j-1][i+(1<<(j-1))]);
		}
		
	public:
		SparseTable(int sz, ll arr[]){
            data.assign(log2_floor(sz)+1, vll(sz));
			_build(arr);
		}
		
		ll get(int i ,int j){
			int k = log2_floor(j-i+1);
			return _conquer(data[k][i], data[k][j-(1<<k)+1]);
		}
};