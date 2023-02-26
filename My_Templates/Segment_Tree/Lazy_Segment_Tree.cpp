#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 9223372036854775807;

// -----------------------------------------------------------------

// -------------------------------------------------------------------||
//  update skip_val - _conquer - _update_method - propagate - update  ||
// -------------------------------------------------------------------||

#define LX (i<<1)
#define RX (i<<1) | 1

// build in O(n) - get in O(logn) - update in O(logn)
class LzySegTree{
    private:
        vector<ll> seg, lzy;
        vector<bool> hav;
        int seg_str, seg_end;

        // sum, mul, xor, ... || min, max, or, and, gcd, ...
        ll skip_val = -INF;
        ll _conquer(ll a1, ll a2){ return max(a1, a2); }
        void _update_method(ll &a, ll val){
            a = val;   // assign
            // a += val;   // increase
        }

        // have to be updated to be suitable with update and conquer
        void _propagate(int i, int l, int r){
            if(!hav[i]) return;
            seg[i] = lzy[i];   // assign & max
            // seg[i] += lzy[i];   // increase & max
            if(l != r){
                lzy[LX] = lzy[i];   // assign & max
                lzy[RX] = lzy[i];   // assign & max
                // lzy[LX] += lzy[i];   // increase
                // lzy[RX] += lzy[i];   // increase
                hav[LX] = 1;
                hav[RX] = 1;
            }
            // lzy[i] = 0;   // increase
            hav[i] = 0;
        }

        void _build(int i, int l, int r, ll a[]){
            if(l == r){
                seg[i] = a[l];
                return;
            }
            int m = (l + r)/2;
            _build(LX, l, m, a);
            _build(RX, m+1, r, a);
            seg[i] = _conquer(seg[LX], seg[RX]);
        }
        
        void _update(int from, int to, ll val, int i, int l, int r){
            _propagate(i, l, r);
            if(to < from) return;
            if(from == l && to == r){
                lzy[i] = val;   // assign
                // lzy[i] += val;   // increase
                hav[i] = 1;
                _propagate(i, l, r);
                return;
            }
            int m = (l + r)/2;
            _update(from, min(to,m), val, LX, l, m);
            _update(max(from,m+1), to, val, RX, m+1, r);
            seg[i] = _conquer(seg[LX], seg[RX]);
        }
        
        ll _get(int from, int to, int i, int l, int r){
            _propagate(i, l, r);
            if(to < from) return skip_val;
            if(from == l && to == r) return seg[i];
            int m = (l + r)/2;
            return _conquer(_get(from, min(to,m), LX, l, m), _get(max(from,m+1), to, RX, m+1, r));
        }
 
    public:
        void resize(int str, int end){
            seg_str = str;
            seg_end = end;
            seg.assign(4*(seg_end-seg_str+1), 0);
            lzy.assign(4*(seg_end-seg_str+1), 0);
            hav.assign(4*(seg_end-seg_str+1), 0);
        }

        void build(ll a[]){
            _build(1, seg_str, seg_end, a);
        }
        
        void update(int from, int to, ll val){
            _update(from, to, val, 1, seg_str, seg_end);
        }
        
        ll get(int from, int to){
            return _get(from, to, 1, seg_str, seg_end);
        }
};
