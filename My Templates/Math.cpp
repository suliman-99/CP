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


int gcd(int a, int b) { return b ? gcd(b,a%b) : a; }
int lcm(int a, int b) { return abs(a * (b/gcd(a,b))); }

ll pow(ll num, ll k){
    if (k < 0) return -1;
    if (k == 0) return 1;
    if (k == 1) return num;
    ll temp = pow(num, k / 2);
    temp *= temp;
    if (k % 2) return temp * num;
    return temp;
}

ll pow_mod(ll num, ll k){
    if (k < 0) return -1;
    if (k == 0) return 1;
    num %= MOD;
    if (k == 1) return num;
    ll temp = pow(num, k / 2);
    temp = (temp * temp)%MOD;
    if (k % 2) return (temp * num)%MOD;
    return temp;
}


ll invers_mod(ll num){
    return pow_mod(num, MOD-2);
}


/*****************************************\
| (a + b) % m = (a%m + b%m)%m             |
| (a * b) % m = (a%m * b%m)%m             |
| (a - b) % m = (a%m - b%m + m)%m         |
| (a / b) % m = (a%m * power(b, m-2)%m)%m |
\*****************************************/


/// --- You Can Process Numbers <= sq(BIGGEST_PRIME) --- ///
const int BIGGEST_PRIME = 1e7 + 5;

bool is_prim[BIGGEST_PRIME];
vi primes;

void calc_primes(){
    is_prim[0] = is_prim[1] = false;
    for(int i = 2 ; i < BIGGEST_PRIME ; i++) is_prim[i] = true;
    primes.clear();
    for(ll i = 2ll ; i < BIGGEST_PRIME ; i++) 
        if(is_prim[i]){
            for(ll j = i * i ; j < BIGGEST_PRIME ; j += i )
                is_prim[j] = false;
            primes.push_back((int)i);
        }
}

vii prime_factors(ll n){
    int idx = 0;
    ll pr = primes[0];
    vii factors;
    while( 1ll * pr * pr <= n ) {
        if( n % pr == 0 ) {
            int cnt = 0;
            while( n % pr == 0 ) {
                n /= pr;
                cnt ++;
            }
            factors.push_back({pr,cnt});
        }
        pr = primes[++idx];
    } 
    if( n != 1 ) factors.push_back({n,1});
    return factors;
}