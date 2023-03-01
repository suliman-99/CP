#include <bits/stdc++.h>
using namespace std;

typedef long long       ll;
const ll INF = 9223372036854775807;
ll n;

// -----------------------------------------------------------------

// ----------------------------------------------------||
// build in O(n) - get in O(logn) - update in O(logn)  ||
// ----------------------------------------------------||


#define LX (i<<1)
#define RX (i<<1)|1
 
// sum, mul, xor, ... || min, max, or, and, gcd, ...
ll seg_skip_val = -INF;
ll seg_conquer(ll a1, ll a2){ return max(a1, a2); }
void seg_update_method(ll &a, ll val){
    a = val;   // assign
    // a += val;   // increase
}

void seg_build(ll seg[], ll arr[], int i = 1, int l = 0, int r = n-1){
    if(l == r){
        seg[i] = arr[l];
        return;
    }
    int m = (l + r)/2;
    seg_build(seg, arr, LX, l, m);
    seg_build(seg, arr, RX, m+1, r);
    seg[i] = seg_conquer(seg[LX], seg[RX]);
}
 

void seg_update(int idx, ll val, ll seg[], int i = 1, int l = 0, int r = n-1){
    if(l == r){
        seg_update_method(seg[i], val);
        return;
    }
    int m = (l + r)/2;
    if(idx <= m) seg_update(idx, val, seg, LX, l, m);
    else seg_update(idx, val, seg, RX, m+1, r);
    seg[i] = seg_conquer(seg[LX], seg[RX]);
}

ll seg_get(int from, int to, ll seg[], int i = 1, int l = 0, int r = n-1){
    if(to < from) return seg_skip_val;
    if(from == l && to == r) return seg[i];
    int m = (l + r)/2;
    return seg_conquer(seg_get(from, min(to, m), seg, LX, l, m), seg_get(max(from, m+1), to, seg, RX, m+1, r));
}
