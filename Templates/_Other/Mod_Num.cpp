#include <bits/stdc++.h>
using namespace std;

typedef long long       ll;
const ll MOD = 1e9 + 7;

// -----------------------------------------------------------------

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

// --------------------------------

struct Num{
    ll val;
    Num(int _val = 0){val = _val % MOD;}
    Num(ll _val = 0){val = _val % MOD;}
    Num operator+(Num other){return val + other.val;}
    Num operator-(Num other){return val - other.val + MOD;}
    Num operator*(Num other){return val * other.val;}
    Num operator/(Num other){return (val-val%other.val) * invers_mod(other.val);}
    void operator+=(Num other){val = (Num(val) + other).val;}
    void operator-=(Num other){val = (Num(val) - other).val;}
    void operator*=(Num other){val = (Num(val) * other).val;}
    void operator/=(Num other){val = (Num(val) / other).val;}
};