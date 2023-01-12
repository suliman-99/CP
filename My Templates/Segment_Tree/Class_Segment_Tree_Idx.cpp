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
            if(arr[idx1] > arr[idx2]) return idx1; /// ----- for max Segment_Tree ----- ///
            // if(arr[idx1] < arr[idx2]) return idx1; /// ----- for min Segment_Tree ----- ///
            else return idx2;
        }

        /// params = [root,  first_element,  last_element, base_array]
        /// params = [ 1  ,       0       ,     n-1      , base_array]
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
        
        /// params = [root,  first_element,  last_element,  index_to_be_updated,  new_value]
        /// params = [ 1  ,       0       ,     n-1      ,  index_to_be_updated,  new_value]
        void _update(int i, int l, int r, int idx, ll val){
            if(l == r){
                arr[l] = val;
                return;
            }
            int m = (l + r)/2;
            if(idx <= m) _update(LX, l, m, idx, val);
            else _update(RX, m+1, r, idx, val);
            seg[i] = conquer(seg[LX], seg[RX]);
        }
        
        /// params = [root,  first_element,  last_element,  from,  to]
        /// params = [ 1  ,       0       ,     n-1      ,  from,  to]
        ll _get(int i, int l, int r, int from, int to){
            if(from > to) return -1;
            if(from == l && to == r) return seg[i];
            int m = (l + r)/2;
            return conquer(_get(LX, l, m, from, min(to,m)), _get(RX, m+1, r, max(from,m+1), to));
        }
 

    public:

        /// params = [first_element,  last_element, base array]
        SegTreeIdx(int str, int end, ll a[]){
            seg_str = str;
            seg_end = end;
            arr = a;
            seg.assign(4*(seg_end-seg_str+1), 0);
            build(1, seg_str, seg_end);
        }
        
        /// params = [index_to_be_updated,  new_value]
        void update(int idx, ll val){
            _update(1, seg_str, seg_end, idx, val);
        }
        
        /// params = [from,  to]
        ll get(int from, int to){
            return _get(1, seg_str, seg_end, from, to);
        }
};
