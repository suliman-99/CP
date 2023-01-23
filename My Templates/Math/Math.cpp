#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
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

template<typename T> T  poww(T num, ll k){
    if (k == 0) return 1;
    if(k % 2) return num * poww(num*num, k>>1);
    return poww(num*num, k>>1);
}

template<typename T> T  pow_mod(T num, ll k){
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


template<typename T> T  arithmetic_series_sum(T a, T q, ll n){
    return (n*(2*a1 + (n-1)*q))/2;
}

template<typename T> T  arithmetic_series_sum_mod(T a, T q, ll n){
    return ((((n%MOD) * ((((2*(a1%MOD))%MOD) + ((((n-1)%MOD)*(q%MOD))%MOD))%MOD))%MOD)*invers_mod(2))%MOD;
}

template<typename T> T  geometric_series_sum(T a, T r, ll n){
    if(r == 1) return a*n;
    if(r == -1) return (n&1) ? a : 0;
    if(abs(r) < 1) return a/(1-r);
    return a*((pow(r, n)-1) / (r-1));
}

template<typename T> T  geometric_series_sum_mod(T a, T r, ll n){
    if(r == 1) return ((a%MOD)*(n%MOD))%MOD;
    if(r == -1) return (n&1) ? (a%MOD) : 0;
    if(abs(r) < 1) return (a/(1-r))%MOD;
    return ((a%MOD) * ((((pow_mod(r, n)+MOD-1)%MOD)*invers_mod(r-1))%MOD))%MOD;
}


