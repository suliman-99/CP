#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// -----------------------------------------------------------------

#define LX (i<<1)
#define RX (i<<1) | 1

class SegTreeIdx {
    private:
        vector<int> seg;
        int seg_str, seg_end;
        ll* arr;

        int conquer(int idx1, int idx2){
            if(idx1 == -1) return idx2;
            if(idx2 == -1) return idx1;
            if(arr[idx1] > arr[idx2]) return idx1;     // for max
            // if(arr[idx1] < arr[idx2]) return idx1;   // for min
            else return idx2;
        }

        void build(int i, int l, int r){
            if(l == r){
                seg[i] = l;
                return;
            }
            int m = (l + r)/2;
            build(LX, l, m);
            build(RX, m+1, r);
            seg[i] = conquer(seg[LX], seg[RX]);
        }
        
        void _update(int idx, ll val, int i, int l, int r){
            if(l == r){
                arr[l] = val;
                return;
            }
            int m = (l + r)/2;
            if(idx <= m) _update(idx, val, LX, l, m);
            else _update(idx, val, RX, m+1, r);
            seg[i] = conquer(seg[LX], seg[RX]);
        }
        
        ll _get(int from, int to, int i, int l, int r){
            if(from > to) return -1;
            if(from == l && to == r) return seg[i];
            int m = (l + r)/2;
            return conquer(_get(from, min(to ,m), LX, l, m), _get(max(from, m+1), to, RX, m+1, r));
        }
 

    public:
        SegTreeIdx(int str, int end, ll a[]){
            seg_str = str;
            seg_end = end;
            arr = a;
            seg.assign(4*(seg_end-seg_str+1), 0);
            build(1, seg_str, seg_end);
        }
        
        void update(int idx, ll val){
            _update(idx, val, 1, seg_str, seg_end);
        }
        
        ll get(int from, int to){
            return _get(from, to, 1, seg_str, seg_end);
        }
};
