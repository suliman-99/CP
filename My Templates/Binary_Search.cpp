#include <bits/stdc++.h>
using namespace std;

typedef long long       ll;

// -----------------------------------------------------------------



int ok1[] = {1,2,2,2,3,4,7,9,9,9,9,9,11,11};



/// ------- Any (ok) Function Return Like This [0,0,0,0,0,1,1,1,1,1,1] ------- ///
bool ok(ll m,ll x){
    return x < ok1[m];
}

ll binary_search(ll l,ll r,ll x){
    ll ans=-1, m;
    while (l<=r){
        m = (l + r) / 2;
        if(ok(m,x)){
            r = m - 1;
            /// ----- To Get First (True) ----- ///
            // ans = m;
        }else{
            l = m + 1;
            /// ----- To Get Last (False) ----- ///
            // ans = m;
        }
    }
    return ans;
}


