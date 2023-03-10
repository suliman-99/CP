#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 9223372036854775807;

// -----------------------------------------------------------------

#define LX (i<<1)
#define RX (i<<1) | 1

// build in O(n) - get in O(logn) - update in O(logn)
class SegTree{
    private:
        vector<ll> seg;
        int seg_str, seg_end;

        // sum, mul, xor, ... || min, max, or, and, gcd, ...
        static const ll skip_val = -INF;
        static ll _conquer(ll a1, ll a2){ return max(a1, a2); }
        static void _update_method(ll &a, ll val){
            a = val;   // assign
            // a += val;   // increase
        }

        void _build(int i, int l, int r, ll arr[]){
            if(l == r){
                seg[i] = arr[l];
                return;
            }
            int m = (l + r)/2;
            _build(LX, l, m, arr);
            _build(RX, m+1, r, arr);
            seg[i] = _conquer(seg[LX], seg[RX]);
        }
        
        void _update(int idx, ll val, int i, int l, int r){
            if(l == r){
                _update_method(seg[i], val);
                return;
            }
            int m = (l + r)/2;
            if(idx <= m) _update(idx, val, LX, l, m);
            else _update(idx, val, RX, m+1, r);
            seg[i] = _conquer(seg[LX], seg[RX]);
        }
        
        ll _get(int from, int to, int i, int l, int r){
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
        }

        void build(ll arr[]){
            _build(1, seg_str, seg_end, arr);
        }
        
        void update(int idx, ll val){
            _update(idx, val, 1, seg_str, seg_end);
        }
        
        ll get(int from, int to){
            return _get(from, to, 1, seg_str, seg_end);
        }
};
