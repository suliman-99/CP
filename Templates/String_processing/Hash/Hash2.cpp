#include <bits/stdc++.h>
using namespace std;

#define S             second
#define F             first

typedef pair<int,int>     ii;
typedef long long       ll;
typedef vector< ll >    vll;

// -----------------------------------------------------------------

class Hash2{
    private:
        static const ll m1 = 2e9+11;
        static const ll p1 = 9973;
        static const ll m2 = 1e9+7;
        static const ll p2 = 5311;
        static const int pow_sz = 1000006;
        static ll pow1[], pow2[], pow3[], pow4[];

        vll h1, h2, h3, h4;

    public:
        Hash2(string s){
            if(pow1[0] == 0){
                pow1[0] = pow2[0] = pow3[0] = pow4[0] = 1;
                for(int i = 1 ; i < pow_sz ; i ++){
                    pow1[i] = (pow1[i-1]*p1)%m1;
                    pow2[i] = (pow2[i-1]*p1)%m2;
                    pow3[i] = (pow3[i-1]*p2)%m1;
                    pow4[i] = (pow4[i-1]*p2)%m2;
                }
            }
            h1.resize(s.size()+1); h1[0] = 0;
            h2.resize(s.size()+1); h2[0] = 0;
            h3.resize(s.size()+1); h3[0] = 0;
            h4.resize(s.size()+1); h4[0] = 0;
            for(int i = 0 ; i < s.size() ; i ++){
                h1[i+1] = (h1[i]*p1 + s[i])%m1;
                h2[i+1] = (h2[i]*p1 + s[i])%m2;
                h3[i+1] = (h3[i]*p2 + s[i])%m1;
                h4[i+1] = (h4[i]*p2 + s[i])%m2;
            }
        }

        pair<ii, ii> get(int l, int r){
            pair<ii, ii> ret;
            ret.F.F= ((h1[r+1] - h1[l]*pow1[r-l+1])%m1 + m1)%m1;
            ret.F.S= ((h2[r+1] - h2[l]*pow2[r-l+1])%m2 + m2)%m2;
            ret.S.F= ((h3[r+1] - h3[l]*pow3[r-l+1])%m1 + m1)%m1;
            ret.S.S= ((h4[r+1] - h4[l]*pow4[r-l+1])%m2 + m2)%m2;
            return ret;
        }

        pair<ii, ii> concatenate(pair<ii, ii> l_hash, pair<ii, ii> r_hash, int r_length){
            pair<ii, ii> ret;
            ret.F.F= (l_hash.F.F*pow1[r_length] + r_hash.F.F)%m1;
            ret.F.S= (l_hash.F.S*pow2[r_length] + r_hash.F.S)%m2;
            ret.S.F= (l_hash.S.F*pow3[r_length] + r_hash.S.F)%m1;
            ret.S.S= (l_hash.S.S*pow4[r_length] + r_hash.S.S)%m2;
            return ret;
        }
};
ll Hash2::pow1[pow_sz];
ll Hash2::pow2[pow_sz];
ll Hash2::pow3[pow_sz];
ll Hash2::pow4[pow_sz];

