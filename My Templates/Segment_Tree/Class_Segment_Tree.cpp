#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 9223372036854775807;

// -----------------------------------------------------------------

#define LX (i<<1)
#define RX (i<<1) | 1

class SegTree {
    private:
        vector<ll> seg;
        int seg_str, seg_end;

        ll skip_val = -INF;
        ll conquer(ll a1, ll a2){ return max(a1, a2); }

        void _build(int i, int l, int r, ll a[]){
            if(l == r){
                seg[i] = a[l];
                return;
            }
            int m = (l + r)/2;
            _build(LX, l, m, a);
            _build(RX, m+1, r, a);
            seg[i] = conquer(seg[LX], seg[RX]);
        }
        
        void _update(int idx, ll val, int i, int l, int r){
            if(l == r){
                seg[i] = val;
                return;
            }
            int m = (l + r)/2;
            if(idx <= m) _update(idx, val, LX, l, m);
            else _update(idx, val, RX, m+1, r);
            seg[i] = conquer(seg[LX], seg[RX]);
        }
        
        ll _get(int from, int to, int i, int l, int r){
            if(from > to) return skip_val;
            if(from == l && to == r) return seg[i];
            int m = (l + r)/2;
            return conquer(_get(from, min(to,m), LX, l, m), _get(max(from,m+1), to, RX, m+1, r));
        }
 
    public:
        void resize(int str, int end){
            seg_str = str;
            seg_end = end;
            seg.assign(4*(seg_end-seg_str+1), 0);
        }

        void build(ll a[]){
            _build(1, seg_str, seg_end, a);
        }
        
        void update(int idx, ll val){
            _update(idx, val, 1, seg_str, seg_end);
        }
        
        ll get(int from, int to){
            return _get(from, to, 1, seg_str, seg_end);
        }
};
