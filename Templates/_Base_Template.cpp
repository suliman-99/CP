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
#define dbg(x)        cout<<#x<<" = "<<x<<endl;
#define SQ(a)         (a)*(a)
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

const ll INF = 4e18;     // 9223372036854775807;
const int OO = 1e9;      // 2147483647;
const ll MOD = 1e9 + 7;  // 998244353;
const ld EPS = 1e-9;
const ld PI  = 3.141592653589793238;

const int TOW = 0b10;
const int FIFTEEN = 0xf;

// -----------------------------------------------------------------


void doTest(){

}


// --------------------------------------

int main(){
    test();
    FastIO
    cout<<fixed<<setprecision(15);

    int tc = 1, tt = 0;
    // scanf("%d", &tc);
    cin>>tc;
    while(tt++ < tc){   
		cout<<"Case #"<<tt<<": ";
        doTest();
    }
}


// -----------------------------------------------------------------