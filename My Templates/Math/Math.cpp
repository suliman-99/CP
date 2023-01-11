#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector< int >   vi;
typedef vector< ii >    vii;
typedef long long ll;
ll MOD = 1e9 + 7;

// -----------------------------------------------------------------


// ----------------------
// floor(2.3) = 2
// floor(-2.3) = -3
// ----------------------
// ceil(2.3) = 3
// ceil(-2.3) = -2
// ----------------------
// log()
// log2()
// log10()
// ----------------------


ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a; }
ll lcm(ll a, ll b) { return abs(a * (b/gcd(a,b))); }

ll poww(ll num, ll k){
    if (k == 0) return 1;
    if(k % 2) return num * poww(num*num, k>>1);
    return poww(num*num, k>>1);
}

ll pow_mod(ll num, ll k){
    if (k == 0) return 1;
    num %= MOD;
    if(k % 2) return (num * pow_mod((num*num)%MOD, k>>1))%MOD;
    return pow_mod((num*num)%MOD, k>>1);
}

/// --- if MOD is prim --- ////
ll invers_mod(ll num){
    return pow_mod(num, MOD-2);
}


/*****************************************\
| (a + b) % m = (a%m + b%m)%m             |
| (a * b) % m = (a%m * b%m)%m             |
| (a - b) % m = (a%m - b%m + m)%m         |
| (a / b) % m = (a%m * power(b, m-2)%m)%m |
\*****************************************/




