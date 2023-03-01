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
		mll st;

        // min, max, or, and, gcd, ...
        ll _conquer(ll a1, ll a2){ return min(a1, a2); }
		
	public:
		void build(int sz, ll arr[]){
            st.assign(log2_floor(sz)+1, vll(sz));
			for(int i = 0 ; i < st[0].size() ; i++) st[0][i] = arr[i];
			for(int j = 1 ; j < st.size() ; j++)
				for(int i = 0 ; i < st[j].size() ; i++)
					st[j][i] = _conquer(st[j-1][i], st[j-1][i+(1<<(j-1))]);
		}
		
		ll get(int i ,int j){
			int k = log2_floor(j-i+1);
			return _conquer(st[k][i], st[k][j-(1<<k)+1]);
		}
};