#include <bits/stdc++.h>
using namespace std;

typedef long long     ll;
ll MOD = 1e9 + 7;

// -----------------------------------------------------------------

const int MAT_N = 60;

void zero_mat(ll a[MAT_N][MAT_N]){
    for(int i = 0 ; i < MAT_N ; i ++)
        for(int j = 0 ; j < MAT_N ; j ++)
            a[i][j] = 0;
}

void identity_mat(ll a[MAT_N][MAT_N]){
    zero_mat(a);
    for(int i = 0 ; i < MAT_N ; i++) a[i][i] = 1;
}

void mat_add_identity(ll a[MAT_N][MAT_N]){
    for(int i = 0 ; i < MAT_N ; i++) a[i][i] += 1;
}

void mat_add_identity_mod(ll a[MAT_N][MAT_N]){
    for(int i = 0 ; i < MAT_N ; i++) a[i][i] = (a[i][i]%MOD + 1)%MOD;
}

ll mat_trace(ll a[MAT_N][MAT_N]){
    ll res = 0;
    for(int i = 0 ; i < MAT_N ; i++) res += a[i][i];
    return res;
}

ll mat_trace_mod(ll a[MAT_N][MAT_N]){
    ll res = 0;
    for(int i = 0 ; i < MAT_N ; i++) res = (res + a[i][i]%MOD)%MOD;
    return res;
}

void mat_add(ll a1[MAT_N][MAT_N], ll a2[MAT_N][MAT_N]){
    for(int i = 0 ; i < MAT_N ; i++)
        for(int j = 0 ; j < MAT_N ; j++)
            a1[i][j] += a2[i][j];
}

void mat_add_mod(ll a1[MAT_N][MAT_N], ll a2[MAT_N][MAT_N]){
    for(int i = 0 ; i < MAT_N ; i++)
        for(int j = 0 ; j < MAT_N ; j++)
            a1[i][j] = (a1[i][j]%MOD + a2[i][j]%MOD)%MOD;
}

void mat_copy(ll a1[MAT_N][MAT_N], ll a2[MAT_N][MAT_N]){
    for(int i = 0 ; i < MAT_N ; i ++)
        for(int j = 0 ; j < MAT_N ; j ++)
            a1[i][j] = a2[i][j];
}

void mat_mul(ll a1[MAT_N][MAT_N], ll a2[MAT_N][MAT_N]){
    ll res[MAT_N][MAT_N];
    zero_mat(res);
    for(int i = 0 ; i < MAT_N ; i ++)
        for(int k = 0 ; k < MAT_N ; k ++)
            if(a1[i][k] != 0) /// --- Optimization --- ///
            for(int j = 0 ; j < MAT_N ; j ++)
                res[i][j] += a1[i][k]*a2[k][j];
    mat_copy(a1, res);
}

void mat_mul_mod(ll a1[MAT_N][MAT_N], ll a2[MAT_N][MAT_N]){
    ll res[MAT_N][MAT_N];
    zero_mat(res);
    for(int i = 0 ; i < MAT_N ; i ++)
        for(int k = 0 ; k < MAT_N ; k ++)
            if(a1[i][k] != 0) /// --- Optimization --- ///
            for(int j = 0 ; j < MAT_N ; j ++)
                res[i][j] = (res[i][j]+((a1[i][k]%MOD)*(a2[k][j]%MOD))%MOD)%MOD;
    mat_copy(a1, res);
}

void mat_pow(ll a[MAT_N][MAT_N], ll k){
    if(k == 1) return;
    if(k == 0) identity_mat(a);
    else if(k&1){
        ll temp[MAT_N][MAT_N];
        mat_copy(temp, a);
        mat_mul(a, a);
        mat_pow(a, k>>1);
        mat_mul(a, temp);
    }else{
        mat_mul(a, a);
        mat_pow(a, k>>1);
    }
}

void mat_pow_mod(ll a[MAT_N][MAT_N], ll k){
    if(k == 1) return;
    if(k == 0) identity_mat(a);
    else if(k&1){
        ll temp[MAT_N][MAT_N];
        mat_copy(temp, a);
        mat_mul_mod(a, a);
        mat_pow_mod(a, k>>1);
        mat_mul_mod(a, temp);
    }else{
        mat_mul_mod(a, a);
        mat_pow_mod(a, k>>1);
    }
}

/// --- a^1 + a^2 + ... + a^k --- ///
void mat_sum_pows(ll a[MAT_N][MAT_N],ll k){
    if(k == 0) zero_mat(a);
    else if(k&1){
        ll temp[MAT_N][MAT_N];
        mat_copy(temp, a);
        mat_sum_pows(a, k-1);
        mat_add_identity(a);
        mat_mul(a, temp);
    }else{
        ll temp[MAT_N][MAT_N];
        mat_copy(temp, a);
        mat_pow(temp, k>>1);
        mat_add_identity(temp);
        mat_sum_pows(a, k>>1);
        mat_mul(a, temp);
    }
}

/// --- a^1 + a^2 + ... + a^k --- With MOD --- ///
void mat_sum_pows_mod(ll a[MAT_N][MAT_N],ll k){
    if(k == 0) zero_mat(a);
    else if(k&1){
        ll temp[MAT_N][MAT_N];
        mat_copy(temp, a);
        mat_sum_pows_mod(a, k-1);
        mat_add_identity_mod(a);
        mat_mul_mod(a, temp);
    }else{
        ll temp[MAT_N][MAT_N];
        mat_copy(temp, a);
        mat_pow_mod(temp, k>>1);
        mat_add_identity_mod(temp);
        mat_sum_pows_mod(a, k>>1);
        mat_mul_mod(a, temp);
    }
}



