#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector< ll >    vll;
typedef vector< vll >   mll;
const int MOD = 1e9 + 7;

/// --- Get Zero Matrix --- ///
mll zero_mat(int n, int m){
    return mll(n, vll(m, 0));
}

/// --- Get Identity Matrix --- ///
mll identity_mat(int n){
    mll identity = zero_mat(n, n);
    for(int i = 0 ; i < n ; i++) identity[i][i] = 1;
    return identity;
}

/// --- Add Identity Matrix  --- ///
mll mat_add_identity(mll a){
    mll res = a;
    for(int i = 0 ; i < res.size() ; i++) res[i][i] += 1;
    return res;
}

/// --- Add Identity Matrix With MOD --- ///
mll mat_add_identity_mod(mll a){
    mll res = a;
    for(int i = 0 ; i < res.size() ; i++) res[i][i] = (res[i][i]%MOD + 1)%MOD;
    return res;
}

/// --- Sum Of Diagonal Matrix --- ///
ll mat_trace(mll a){
    ll res = 0;
    for(int i = 0 ; i < a.size() ; i++) res += a[i][i];
    return res;
}

/// --- Sum Of Diagonal Matrix With MOD --- ///
ll mat_trace_mod(mll a){
    ll res = 0;
    for(int i = 0 ; i < a.size() ; i++) res = (res + a[i][i]%MOD)%MOD;
    return res;
}

/// --- Sum Two Matrix  --- ///
mll mat_add(mll a1, mll a2){
    mll res = zero_mat(a1.size(), a1[0].size());
    for(int i = 0 ; i < a1.size() ; i++)
        for(int j = 0 ; j < a1[0].size() ; j++)
            res[i][j] = a1[i][j] + a2[i][j];
    return res;
}

/// --- Sum Two Matrix With MOD  --- ///
mll mat_add_mod(mll a1, mll a2){
    mll res = zero_mat(a1.size(), a1[0].size());
    for(int i = 0 ; i < a1.size() ; i++)
        for(int j = 0 ; j < a1[0].size() ; j++)
            res[i][j] = (a1[i][j]%MOD + a2[i][j]%MOD)%MOD;
    return res;
}

/// --- Multiplication Two Matrix  --- ///
mll mat_mul(mll a1, mll a2){
    mll res = zero_mat(a1.size(), a2[0].size());
    for(int i = 0 ; i < a1.size() ; i++)
        for(int k = 0 ; k < a1[0].size() ; k++)
            if( a1[i][k] != 0 ) /// --- Optimization --- ///
                for(int j = 0 ; j < a2[0].size() ; j++)
                    res[i][j] += a1[i][k] * a2[k][j];
    return res;
}

/// --- Multiplication Two Matrix With MOD --- ///
mll mat_mul_mod(mll a1, mll a2){
    mll res = zero_mat(a1.size(), a2[0].size());
    for(int i = 0 ; i < a1.size() ; i++)
        for(int k = 0 ; k < a1[0].size() ; k++)
            if( a1[i][k] != 0 ) /// --- Optimization --- ///
                for(int j = 0 ; j < a2[0].size() ; j++)
                    res[i][j] = (res[i][j] + ((a1[i][k] % MOD) * (a2[k][j] % MOD)) % MOD) % MOD;
    return res;
}

/// --- Power(Matrix ,k) --- ///
mll mat_pow(mll a, ll k){
    if(k == 0) return identity_mat(a.size());
    if(k&1) return mat_mul(a, mat_pow(a, k-1));
    return mat_pow(mat_mul(a, a), k>>1);
}

/// --- Power(Matrix ,k) With MOD --- ///
mll mat_pow_mod(mll a, ll k){
    if(k == 0) return identity_mat(a.size());
    if(k&1) return mat_mul_mod(a, mat_pow_mod(a, k-1));
    return mat_pow_mod(mat_mul_mod(a, a), k>>1);
}

/// --- a^1 + a^2 + ... + a^k --- ///
mll mat_sum_pows(mll a, ll k){
    if(k == 0) return zero_mat(a.size(), a.size());
    if(k&1) return mat_mul(a, mat_add_identity(mat_sum_pows(a, k-1)));
    return mat_mul(mat_sum_pows(a, k>>1), mat_add_identity(mat_pow(a, k>>1)));
}

/// --- a^1 + a^2 + ... + a^k --- With MOD --- ///
mll mat_sum_pows_mod(mll a, ll k){
    if(k == 0) return zero_mat(a.size(), a.size());
    if(k&1) return mat_mul_mod(a, mat_add_identity_mod(mat_sum_pows_mod(a, k-1)));
    return mat_mul_mod(mat_sum_pows_mod(a, k>>1), mat_add_identity_mod( mat_pow_mod(a, k>>1)));
}


