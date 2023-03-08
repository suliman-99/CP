#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// -----------------------------------------------------------------

#define LX (i<<1)
#define RX (i<<1) | 1

// build in O(n) - get in O(logn) - update in O(logn)
class SegTreeIdx{
    private:
        vector<int> seg;
        vector<ll> arr;
        int seg_str, seg_end;

        // min, max, ...
        int _conquer(int idx1, int idx2){
            if(idx1 == -1) return idx2;
            if(idx2 == -1) return idx1;
            if(arr[idx1] > arr[idx2]) return idx1;     // for max
            // if(arr[idx1] < arr[idx2]) return idx1;   // for min
            else return idx2;
        }
        static void _update_method(ll &a, ll val){
            a = val;   // assign
            // a += val;   // increase
        }

        void _build(int i, int l, int r){
            if(l == r){
                seg[i] = l;
                return;
            }
            int m = (l + r)/2;
            _build(LX, l, m);
            _build(RX, m+1, r);
            seg[i] = _conquer(seg[LX], seg[RX]);
        }
        
        void _update(int idx, ll val, int i, int l, int r){
            if(l == r){
                _update_method(arr[l], val);
                return;
            }
            int m = (l + r)/2;
            if(idx <= m) _update(idx, val, LX, l, m);
            else _update(idx, val, RX, m+1, r);
            seg[i] = _conquer(seg[LX], seg[RX]);
        }
        
        ll _get(int from, int to, int i, int l, int r){
            if(to < from) return -1;
            if(from == l && to == r) return seg[i];
            int m = (l + r)/2;
            return _conquer(_get(from, min(to ,m), LX, l, m), _get(max(from, m+1), to, RX, m+1, r));
        }
 

    public:
        void resize(int str, int end){
            seg_str = str;
            seg_end = end;
            seg.assign(4*(seg_end-seg_str+1), 0);
            arr.assign(seg_end-seg_str+1, 0);
        }

        void build(ll arr[]){
            for(int i = seg_str ; i <= seg_end ; i ++) this->arr[i-seg_str] = arr[i];
            _build(1, seg_str, seg_end);
        }
        
        void update(int idx, ll val){
            _update(idx, val, 1, seg_str, seg_end);
        }
        
        ll get(int from, int to){
            return _get(from, to, 1, seg_str, seg_end);
        }
};
