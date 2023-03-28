#include <bits/stdc++.h>
using namespace std;

typedef long long       ll;

// -----------------------------------------------------------------

ll turn_on(ll mask, int i){ return mask|(1<<i); }

ll turn_off(ll mask, int i){ return (mask|(1<<i))^(1<<i); }

bool is_on(ll mask, int i){ return mask&(1<<i); }

bool is_off(ll mask, int i){ return !(mask&(1<<i)); }

// delete i-th bit from the mast and concatenate the left ans right parts
// del(01010, 2) -> (0 0110) | del(01010, 1) -> (0 0100)
ll del(ll mask, int i){ return (((mask>>(i+1))<<i)|(mask%(1<<i))); }

