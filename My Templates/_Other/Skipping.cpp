#include <bits/stdc++.h>
using namespace std;

typedef long long       ll;


/// -------------------- skip elements with condition -------------------- ///
const int NEXT_N = 1e6 + 5e3;
int first_idx, last_idx;

int a[NEXT_N], next_idx[NEXT_N];

bool next_skip(int idx){
    /// return true to skip the element at idx & false otherwise
    return (a[idx] == 0);
}

void next_fill(){
    next_idx[last_idx] = last_idx + 1;
    for(int i = last_idx - 1 ; i >= first_idx ; i--)
        if(next_skip(i+1)) next_idx[i] = next_idx[i+1];
        else next_idx[i] = i+1;
}


