#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector< int >   vi;
typedef vector< ii >    vii;
typedef long long ll;



/*********       is_prime_f      *********\
|                                         |
|     0 < n < 1e7     :         O(1)      |
|                                         |
|   1e7 < n < 1e14    :    O(sqrt(n)/10)  |
|                                         |
|  1e14 < n           :         Can't     |
|                                         |
\*****************************************/

/**********    prime_factors    **********\
|                                         |
|      0 < n < 1e14   :   O(sqrt(n)/10)   |
|                                         |
|   1e14 < n          :       can't       |
|                                         |
\*****************************************/


/// --- You Can Process Numbers <= BIGGEST_PRIME^2 --- ///
const int BIGGEST_PRIME = 1e7 + 5;

bool is_prime[BIGGEST_PRIME];
vi primes;

void calc_primes(){
    is_prime[0] = is_prime[1] = false;
    for(int i = 2 ; i < BIGGEST_PRIME ; i++) is_prime[i] = true;
    primes.clear();
    for(ll i = 2ll ; i < BIGGEST_PRIME ; i++) 
        if(is_prime[i]){
            for(ll j = i * i ; j < BIGGEST_PRIME ; j += i )
                is_prime[j] = false;
            primes.push_back((int)i);
        }
}

bool is_prime_f(ll x){
    if(x < BIGGEST_PRIME ) return is_prime[x];
    for(int p : primes)
        if(x%p == 0) 
            return false;
    return true;
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
