#include <bits/stdc++.h>
using namespace std;

typedef long long       ll;
typedef vector< ll >    vll;

// -----------------------------------------------------------------

class FenTreePURQ{
	private:
		vll data;

	public:
		FenTreePURQ(int sz){ data.assign(sz+1, 0); }
         
        void build(ll a[]){
            for(int i = 1 ; i < data.size() ; i ++){
                data[i] += a[i-1];
                if(i+(i&(-i)) < data.size()) data[i+(i&(-i))] += data[i];
            }
        }
		
		ll get(int i){
			ll sum=0; i++;
			for(;i;i-=(i&(-i))) sum += data[i];
			return sum;
		}
		
		ll get(int i, int j){ return get(j) - get(i-1); }
		
		void update(int i, ll d){ i++; for(;i<data.size();i+=(i&(-i))) data[i] += d; }
        
        // find first idx : k <= pre[idx]
		int lower_bound_on_pre(int k){
			int p = 1 ,i = 0;
			while(p*2 < data.size()) p *= 2;
			for(;p;p/=2) 
                if(i+p < data.size() && data[i + p] < k){
                    k -= data[i + p];
                    i += p;
				}
			return i;
		}
};

class FenTreeRUPQ{
	private:
		vll cpy;
		FenTreePURQ purq;

	public:
		FenTreeRUPQ(int sz) : purq(FenTreePURQ(sz+1)) { cpy.assign(sz, 0); }

		void build(ll a[]){ for(int i = 0 ; i < cpy.size() ; i ++) cpy[i] = a[i]; }
		
		void update(int i, int j, ll d){ purq.update(i, +d); purq.update(j+1, -d); }
		
		ll get(int i){ return cpy[i] + purq.get(i); }
};

class FenTreeRURQ{
	private:
		vll pre;
		FenTreePURQ purq;
		FenTreeRUPQ rupq;
		
	public:
		FenTreeRURQ(int sz) :purq(FenTreePURQ(sz+1)), rupq(FenTreeRUPQ(sz)) { pre.assign(sz+1, 0); }
		
		void build(ll a[]){ for(int i = 1 ; i < pre.size() ; i ++) pre[i] = pre[i-1] + a[i-1]; }

		void update(int i ,int j ,ll d){
			rupq.update(i, j, d);
			purq.update(i, -d*i);
			purq.update(j+1, +d*(j+1));
		}
		
		ll get(int i){ return pre[i+1] + rupq.get(i)*(i+1) + purq.get(i); }
		
		ll get(int i, int j){ return get(j) - get(i - 1); }
};
