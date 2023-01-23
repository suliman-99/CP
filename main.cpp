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
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI  = 3.141592653589793238;

const int TOW = 0b10;
const int FIFTEEN = 0xf;

int tc = 1;

// -----------------------------------------------------------------

const int N = 3e5 + 5e3;

ll n, a[N];

// --------------------------------------

// --------------------------------------

void doTest(){
    cin>>n;
    for(int i = 0 ; i < n ; i ++){
        cin>>a[i];
    }

    
}


// --------------------------------------

int main(){
    test();
    FastIO
    cout<<fixed<<setprecision(15);



    // scanf("%d",&tc);
    cin>>tc;
    while(tc--) doTest();
}

// -----------------------------------------------------------------