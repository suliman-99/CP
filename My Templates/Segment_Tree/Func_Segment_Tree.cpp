#include <bits/stdc++.h>
using namespace std;

typedef long long       ll;
const ll INF = 9223372036854775807;
ll n;

// -----------------------------------------------------------------

#define LX (i<<1)
#define RX (i<<1)|1
 
ll skip_val = -INF;
ll seg_conquer(ll a1, ll a2){ return max(a1, a2); }

void seg_build(ll seg[], ll a[], int i = 1, int l = 0, int r = n-1){
    if(l == r){
        seg[i] = a[l];
        return;
    }
    int m = (l + r)/2;
    seg_build(seg, a, LX, l, m);
    seg_build(seg, a, RX, m+1, r);
    seg[i] = seg_conquer(seg[LX], seg[RX]);
}
 

void seg_update(int idx, ll val, ll seg[], int i = 1, int l = 0, int r = n-1){
    if(l == r){
        seg[i] = val;
        return;
    }
    int m = (l + r)/2;
    if(idx <= m) seg_update(idx, val, seg, LX, l, m);
    else seg_update(idx, val, seg, RX, m+1, r);
    seg[i] = seg_conquer(seg[LX], seg[RX]);
}
 
ll seg_get(int from, int to, ll seg[], int i = 1, int l = 0, int r = n-1){
    if(from > to) return skip_val;
    if(from == l && to == r) return seg[i];
    int m = (l + r)/2;
    return seg_conquer(seg_get(from, min(to, m), seg, LX, l, m), seg_get(max(from, m+1), to, seg, RX, m+1, r));
}
