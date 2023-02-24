#include <bits/stdc++.h>
using namespace std;
int mod = 998244353;
struct Mint{
    int val;
    Mint(int _val = 0){val = _val % mod;}
    Mint(long long _val = 0){val = _val % mod;}
    Mint operator+(Mint oth){return val + oth.val;}
    Mint operator*(Mint oth){return 1LL * val * oth.val;}
    Mint operator-(Mint oth){return val - oth.val + mod;}
    void operator+=(Mint oth){val = (Mint(val) + oth).val;}
    void operator-=(Mint oth){val = (Mint(val) - oth).val;}
    void operator*=(Mint oth){val = (Mint(val) * oth).val;}
};