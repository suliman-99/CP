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
|      0 < n < 1e7    :     O(log(n))     |
|                                         |
|    1e7 < n          :       can't       |
|                                         |
\*****************************************/


const int BIGGEST_PRIME = 1e7 + 5;
int small_primes[BIGGEST_PRIME], big_primes[BIGGEST_PRIME];
vi primes;

void calc_primes(){
    for(int i = 2 ; i < BIGGEST_PRIME ; i++) small_primes[i] = big_primes[i] = i;
    primes.clear();
    for(ll i = 2 ; i < BIGGEST_PRIME ; i++){
        if(small_primes[i] == i){
            for(ll j = i * 2 ; j < BIGGEST_PRIME ; j += i ){
                if(small_primes[j] == j) small_primes[j] = i;
                big_primes[j] = i;
            }
            primes.push_back(i);
        }
    }
}

bool is_prime_f(ll x){
    if(x < BIGGEST_PRIME ) return (small_primes[x] == x);
    for(int p : primes)
        if(x%p == 0) 
            return false;
    return true;
}


vii prime_factors(ll x){
    vii factors;
    while( x > 1 ){
        int small_prim = small_primes[x];
        int cnt = 0;
        while( x % small_prim == 0 ){
            x /= small_prim;
            cnt ++;
        }
        factors.push_back({small_prim, cnt});
    } 
    return factors;
}
