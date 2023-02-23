#include <bits/stdc++.h>
using namespace std;

typedef long long       ll;

// -----------------------------------------------------------------


#define LX (i<<1)
#define RX (i<<1)|1

/// use prefix technique for ( --- sum --- xor --- ) 
/// seg is just used for ( --- max --- min --- ) 
ll seg_conquer(ll a1, ll a2){
    return max(a1, a2);
    // return min(a1, a2);
}

/// params = [root,  first_element,  last_element, seg_array, base_array]
/// params = [ 1  ,       0       ,     n-1      , seg_array, base_array]
void seg_build(int i, int l, int r, ll seg[], ll a[]){
    if(l == r){
        seg[i] = a[l];
        return;
    }
    int m = (l + r)/2;
    seg_build(LX, l, m, seg, a);
    seg_build(RX, m+1, r, seg, a);
    seg[i] = seg_conquer(seg[LX], seg[RX]);
}
 
/// params = [root,  first_element,  last_element,  index_to_be_updated,  new_value, seg_array]
/// params = [ 1  ,       0       ,     n-1      ,  index_to_be_updated,  new_value, seg_array]
void seg_update(int i, int l, int r, int idx, ll val, ll seg[]){
    if(l == r){
        seg[i] = val;
        return;
    }
    int m = (l + r)/2;
    if(idx <= m) seg_update(LX, l, m, idx, val, seg);
    else seg_update(RX, m+1, r, idx, val, seg);
    seg[i] = seg_conquer(seg[LX], seg[RX]);
}
 
/// params = [root,  first_element,  last_element,  from,  to, seg_array]
/// params = [ 1  ,       0       ,     n-1      ,  from,  to, seg_array]
ll seg_get(int i, int l, int r, int from, int to, ll seg[]){
    if(from > to) return 0;
    if(from == l && to == r) return seg[i];
    int m = (l + r)/2;
    return seg_conquer(seg_get(LX, l, m, from, min(to,m), seg), seg_get(RX, m+1, r, max(from,m+1), to, seg));
}