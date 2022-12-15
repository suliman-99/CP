#include <bits/stdc++.h>
using namespace std;

typedef long long       ll;

// -----------------------------------------------------------------

const int SEG_N = 1e5 + 5e3;
int seg_str = 0, seg_end;


ll a[SEG_N], s[4*SEG_N];

/// use prefix technique for ( --- sum --- xor --- ) 
ll seg_conquer(ll a1,ll a2){
    /// seg id used for ( --- max --- min --- ) 
    return max(a1,a2);
}

void seg_build(){
    _seg_build(1,seg_str,seg_end);
}

void seg_update(int idx,ll val){
    _seg_update(1,seg_str,seg_end,idx,val);
}

ll seg_get(int from,int to){
    return _seg_get(1,seg_str,seg_end,from,to);
}

/// ---------------------------------------------

#define LX (i << 1)
#define RX (i << 1) | 1

/// params = [root,  first_element,  last_element]
void _seg_build(int i,int l,int r){
    if(l == r){
        s[i] = a[l];
        return;
    }
    int m = (l + r)/2;
    _seg_build(LX,l,m);
    _seg_build(RX,m+1,r);
    s[i] = seg_conquer(s[LX],s[RX]);
}
 
/// params = [root,  first_element,  last_element,  index_to_be_updated,  new_value]
void _seg_update(int i,int l,int r,int idx,ll val){
    if(l == r){
        s[i] = val;
        return;
    }
    int m = (l + r)/2;
    if(idx <= m) _seg_update(LX,l,m,idx,val);
    else _seg_update(RX,m+1,r,idx,val);
    s[i] = seg_conquer(s[LX],s[RX]);
}
 
/// params = [root,  first_element,  last_element,  from,  to]
ll _seg_get(int i,int l,int r,int from,int to){
    if(from > to) return 0;
    if(from == l && to == r) return s[i];
    int m = (l + r)/2;
    return seg_conquer(_seg_get(LX,l,m,from,min(to,m)),_seg_get(RX,m+1,r,max(from,m+1),to));
}
 