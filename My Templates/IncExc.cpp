#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------------------

void test(){
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

// -----------------------------------------------------------------

#define FastIO        cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define printv(v)     for(auto x:v){cout<<x<<" ";}cout<<endl;
#define dbg(x)        cout<<#x<<" = "<<x<<endl;
#define SQ(a)         (a)*(a)
#define PB            push_back
#define S             second
#define F             first


// -----------------------------------------------------------------

typedef pair<int,int>     ii;

typedef vector<int>       vi;
typedef vector<ii>        vii;

typedef vector<vi>        mi;
typedef vector<vii>       mii;

// --------------------------------------

typedef long long       ll;

typedef pair<ll, ll>   pll;

typedef vector< ll >    vll;
typedef vector< pll >   vpll;

typedef vector< vll >   mll;
typedef vector< vpll >   mpll;

typedef unsigned long long       ull;
typedef long double     ld;

// --------------------------------------

const ll INF = 9223372036854775807;
const int OO = 2147483647;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const ld PI  = 3.141592653589793238;

const int TOW = 0b10;
const int FIFTEEN = 0xf;

int tc = 1;

// -----------------------------------------------------------------

const int N = 3e5 + 5e3;

ll ans;
int n, m, l, x;
int c, x1, p, ms, mask1, num, on;
vii f1, f2;
vi diff;

// --------------------------------------

template<typename T>T gcd(T a, T b) { return b ? gcd(b,a%b) : a; }

const int BIGGEST_PRIME = 4e4 + 5;
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

// --------------------------------------

void doTest(){
    cin>>n>>m;
    cin>>l;
    f1 = prime_factors(l);
    ans = 1;
    for(int i = 1 ; i < n ; i ++){
        cin>>x;
        if(ans == 0 || gcd(l, x) != x) {
            ans = 0;
            continue;
        }
        f2.clear();
        for(int j = 0 ; j < f1.size() ; j ++){
            c = 0, x1 = x;
            while(x1%f1[j].F == 0){
                x1 /= f1[j].F;
                c++;
            }
            f2.push_back({f1[j].F,c});
        }
        diff.clear();
        for(int j = 0 ; j < f1.size() ; j ++)
            if(f1[j].S > f2[j].S) diff.push_back(f1[j].F);
        p = m/x, ms = 0, l = x, f1 = f2;
        if(diff.size() != 0)
        for(int mask = 1 ; mask < (1<<diff.size()) ; mask++){
            mask1 = mask, num = 1, on = 0;
            for(int k = 0 ; mask1 > 0 ; k++){
                if(mask1%2){
                    num *= diff[k];
                    on++;
                }
                mask1 /= 2;
            }
            ms += (on%2) ? p/num : -p/num;
        }
        ans *= p - ms;
        ans %= MOD;
    }
    cout<<ans<<endl;
}



// --------------------------------------

int main(){
    test();
    FastIO
    cout<<fixed<<setprecision(15);

    calc_primes();


    // scanf("%d",&tc);
    cin>>tc;
    while(tc--) doTest();
}

// -----------------------------------------------------------------