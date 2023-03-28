#include <bits/stdc++.h>
using namespace std;

typedef long long       ll;
typedef vector< ll >    vll;

// -----------------------------------------------------------------

struct DRH_Result{
    ll h1, h2, h3, h4;

    int operator==(DRH_Result const& other){
        return (h1 == other.h1 && h2 == other.h2 && h3 == other.h3 && h4 == other.h4);
    }
};


class DoubleRollingHash{
    private:
        static const ll m1 = 2000000011;
        static const ll p1 = 5311;
        static const ll m2 = 1000000007;
        static const ll p2 = 1331;
        static const int pow_sz = 1000006;
        static ll pow1[], pow2[], pow3[], pow4[];

        vll h1, h2, h3, h4;

    public:
        DoubleRollingHash(string s){
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

        DRH_Result get(int l, int r){
            DRH_Result ret;
            ret.h1 = ((h1[r+1] - h1[l]*pow1[r-l+1])%m1 + m1)%m1;
            ret.h2 = ((h2[r+1] - h2[l]*pow2[r-l+1])%m2 + m2)%m2;
            ret.h3 = ((h3[r+1] - h3[l]*pow3[r-l+1])%m1 + m1)%m1;
            ret.h4 = ((h4[r+1] - h4[l]*pow4[r-l+1])%m2 + m2)%m2;
            return ret;
        }

        DRH_Result concatenate(DRH_Result l_hash, DRH_Result r_hash, int r_length){
            DRH_Result ret;
            ret.h1 = (l_hash.h1*pow1[r_length] + r_hash.h1)%m1;
            ret.h2 = (l_hash.h2*pow2[r_length] + r_hash.h2)%m2;
            ret.h3 = (l_hash.h3*pow3[r_length] + r_hash.h3)%m1;
            ret.h4 = (l_hash.h4*pow4[r_length] + r_hash.h4)%m2;
            return ret;
        }
};
ll DoubleRollingHash::pow1[pow_sz];
ll DoubleRollingHash::pow2[pow_sz];
ll DoubleRollingHash::pow3[pow_sz];
ll DoubleRollingHash::pow4[pow_sz];