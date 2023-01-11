#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// -----------------------------------------------------------------

#define LX (i<<1)
#define RX (i<<1) | 1

class SegTree {
    private:
        vector<ll> seg;
        int seg_str, seg_end;

        /// use prefix technique for ( --- sum --- xor --- ) 
        /// seg is just used for ( --- max --- min --- ) 
        ll conquer(ll a1, ll a2){
            return max(a1, a2);
            // return min(a1, a2);
        }

        /// params = [root,  first_element,  last_element, base_array]
        /// params = [ 1  ,       0       ,     n-1      , base_array]
        void build(int i, int l, int r, ll a[]){
            if(l == r){
                seg[i] = a[l];
                return;
            }
            int m = (l + r)/2;
            build(LX, l, m, a);
            build(RX, m+1, r, a);
            seg[i] = conquer(seg[LX], seg[RX]);
        }
        
        /// params = [root,  first_element,  last_element,  index_to_be_updated,  new_value]
        /// params = [ 1  ,       0       ,     n-1      ,  index_to_be_updated,  new_value]
        void _update(int i, int l, int r, int idx, ll val){
            if(l == r){
                seg[i] = val;
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
            if(from > to) return 0;
            if(from == l && to == r) return seg[i];
            int m = (l + r)/2;
            return conquer(_get(LX, l, m, from, min(to,m)), _get(RX, m+1, r, max(from,m+1), to));
        }
 

    public:

        /// params = [first_element,  last_element]
        SegTree(int str, int end){
            seg_str = str;
            seg_end = end;
            seg.assign(4*(seg_end-seg_str+1), 0);
        }

        /// params = [first_element,  last_element, base array]
        SegTree(int str, int end, ll a[]){
            seg_str = str;
            seg_end = end;
            seg.assign(4*(seg_end-seg_str+1), 0);
            build(1, seg_str, seg_end, a);
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
