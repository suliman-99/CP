#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// -----------------------------------------------------------------


bool is_diff_direction(ll x1, ll y1, ll x2, ll y2, ll a, ll b, ll c){
    if(b == 0) return ((x1*a+c) * (x2*a+c) < 0);
    return ((y1*b+a*x1+c) * (y2*b+a*x2+c) < 0);
}

