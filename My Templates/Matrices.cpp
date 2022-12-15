#include <bits/stdc++.h>
using namespace std;

typedef long long     ll;
ll MOD = 1e9 + 7;

// -----------------------------------------------------------------

const int MAT_N = 60;


/// --- Get Zero Matrix --- ///
void zero_mat(ll a[MAT_N][MAT_N]){
    for(int i = 0 ; i < MAT_N ; i ++)
        for(int j = 0 ; j < MAT_N ; j ++)
            a[i][j] = 0;
}

/// --- Get Identity Matrix --- ///
void identity_mat(ll a[MAT_N][MAT_N]){
    zero_mat(a);
    for(int i = 0 ; i < MAT_N ; i++) a[i][i] = 1;
}

/// --- Sum a Matrix With Identity --- ///
void mat_add_identity(ll a[MAT_N][MAT_N]){
    for(int i = 0 ; i < MAT_N ; i++) a[i][i] += 1;
}

/// --- Sum Of Diagonal Matrix --- ///
ll mat_trace(ll a[MAT_N][MAT_N]){
    ll res = 0;
    for(int i = 0 ; i < MAT_N ; i++) res += a[i][i];
    return res;
}

/// --- Sum Two Matrix  --- ///
void mat_add(ll a1[MAT_N][MAT_N],ll a2[MAT_N][MAT_N]){
    for(int i = 0 ; i < MAT_N ; i++)
        for(int j = 0 ; j < MAT_N ; j++)
            a1[i][j] += a1[i][j];
}

void mat_copy(ll a1[MAT_N][MAT_N],ll a2[MAT_N][MAT_N]){
    for(int i = 0 ; i < MAT_N ; i ++)
        for(int j = 0 ; j < MAT_N ; j ++)
            a1[i][j] = a2[i][j];
}


void mat_mul_mod(ll a1[MAT_N][MAT_N],ll a2[MAT_N][MAT_N]){
    ll res[MAT_N][MAT_N];
    for(int i = 0 ; i < MAT_N ; i ++)
        for(int j = 0 ; j < MAT_N ; j ++){
            res[i][j] = 0;
            for(int k = 0 ; k < MAT_N ; k ++)
                res[i][j] = (res[i][j]+(a1[i][k]*a2[k][j])%MOD)%MOD;
        }
    mat_copy(a1, res);
}

void mat_pow_mod(ll a1[MAT_N][MAT_N],ll num){
    if(num < 2) return;
    ll temp[MAT_N][MAT_N];
    mat_copy(temp, a1);
    mat_mul_mod(a1,a1);
    mat_pow_mod(a1,num/2);
    if(num%2) mat_mul_mod(a1,temp);
}

void mat_mul(ll a1[MAT_N][MAT_N],ll a2[MAT_N][MAT_N]){
    ll res[MAT_N][MAT_N];
    for(int i = 0 ; i < MAT_N ; i ++)
        for(int j = 0 ; j < MAT_N ; j ++){
            res[i][j] = 0;
            for(int k = 0 ; k < MAT_N ; k ++)
                res[i][j] += a1[i][k]*a2[k][j];
        }
    mat_copy(a1, res);
}

void mat_pow(ll a1[MAT_N][MAT_N],ll num){
    if(num < 2) return;
    ll temp[MAT_N][MAT_N];
    mat_copy(temp, a1);
    mat_mul(a1,a1);
    mat_pow(a1,num/2);
    if(num%2) mat_mul(a1,temp);
}


