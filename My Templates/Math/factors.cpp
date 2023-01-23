#include <bits/stdc++.h>
using namespace std;

typedef vector<int>       vi;
typedef vector<vi>        mi;

// -----------------------------------------------------------------

const int BIGGEST_FACTOR = 1e7 + 5;
mi factors;

void calc_facors(){
    factors.clear();
    factors.resize(BIGGEST_FACTOR+1);
    for(int i = 1 ; i <= BIGGEST_FACTOR ; i ++){
        for(int j = i ; j <= BIGGEST_FACTOR ; j += i){
            factors[j].push_back(i);
        }
    }
}
