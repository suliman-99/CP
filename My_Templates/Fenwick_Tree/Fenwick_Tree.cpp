#include <bits/stdc++.h>
using namespace std;

typedef long long       ll;
typedef vector< ll >    vll;

// -----------------------------------------------------------------

// build in O(n) - get in O(logn) - update in O(logn)
class FenTreePURQ{
	private:
		vll ft;

	public:
		void resize(int sz){ ft.assign(sz+1, 0); }
         
        void build(ll arr[]){
            for(int i = 1 ; i < ft.size() ; i ++){
                ft[i] += arr[i-1];
                if(i+(i&(-i)) < ft.size()) ft[i+(i&(-i))] += ft[i];
            }
        }
		
		ll get(int i){
			ll sum=0; i++;
			for(;i;i-=(i&(-i))) sum += ft[i];
			return sum;
		}
		
		ll get(int i, int j){ return get(j) - get(i-1); }
		
		void update(int i, ll d){ i++; for(;i<ft.size();i+=(i&(-i))) ft[i] += d; }
        
        // find first idx : k <= pre[idx]
		int lower_bound_on_pre(int k){
			int p = 1 ,i = 0;
			while(p*2 < ft.size()) p *= 2;
			for(;p;p/=2) 
                if(i+p < ft.size() && ft[i + p] < k){
                    k -= ft[i + p];
                    i += p;
				}
			return i;
		}
};

class FenTreeRUPQ{
	private:
		vll cpy;
		FenTreePURQ purq;
		int sz;

	public:
		void resize(int sz){ purq.resize(sz+1); this->sz = sz; }

		void build(ll arr[]){ 
			cpy.assign(sz, 0); 
			for(int i = 0 ; i < cpy.size() ; i ++) 
				cpy[i] = arr[i]; 
		}
		
		void update(int i, int j, ll d){ purq.update(i, +d); purq.update(j+1, -d); }
		
		ll get(int i){ return cpy[i] + purq.get(i); }
};

class FenTreeRURQ{
	private:
		vll pre;
		FenTreePURQ purq;
		FenTreeRUPQ rupq;
		int sz;
		
	public:
		void resize(int sz){ purq.resize(sz+1); rupq.resize(sz); this->sz = sz; }
		
		void build(ll arr[]){
			pre.assign(sz+1, 0);
			for(int i = 1 ; i < pre.size() ; i ++) 
				pre[i] = pre[i-1] + arr[i-1]; 
		}

		void update(int i ,int j ,ll d){
			rupq.update(i, j, d);
			purq.update(i, -d*i);
			purq.update(j+1, +d*(j+1));
		}
		
		ll get(int i){ return pre[i+1] + rupq.get(i)*(i+1) + purq.get(i); }
		
		ll get(int i, int j){ return get(j) - get(i - 1); }
};
