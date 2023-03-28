#include <bits/stdc++.h>
using namespace std;

typedef long long       ll;
typedef vector< ll >    vll;

// -----------------------------------------------------------------

class RollingHash{
    private:
        static const ll m = 2000000011;
        static const ll p = 5311;
        static const int pow_sz = 1000006;
        static ll pow[];

        vll h;

    public:
        RollingHash(string s){
            if(pow[0] == 0){
                pow[0] = 1;
                for(int i = 1 ; i < pow_sz ; i ++) 
                    pow[i] = (pow[i-1]*p)%m;
            }
            h.resize(s.size()+1); h[0] = 0;
            for(int i = 0 ; i < s.size() ; i ++){
                h[i+1] = (h[i]*p + s[i])%m;
            }
        }

        ll get(int l, int r){
            return ((h[r+1] - h[l]*pow[r-l+1])%m + m)%m;
        }

        ll concatenate(ll l_hash, ll r_hash, int r_length){
            return (l_hash*pow[r_length] + r_hash)%m;
        }
};
ll RollingHash::pow[pow_sz];
