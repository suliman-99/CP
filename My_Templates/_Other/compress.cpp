#include <bits/stdc++.h>
using namespace std;

#define S             second
#define F             first
typedef pair<int,int>     ii;
typedef long long       ll;
typedef vector< ll >    vll;

// -----------------------------------------------------------------

// compress the source array & return max element
int compress(ll source[],int sz){
    ii temp[sz]; int mx = 0;
    for(int i = 0 ; i < sz ; i ++){
        temp[i].F = source[i];
        temp[i].S = i;
    }
    sort(temp, temp+sz);
    for(int i = 0 ; i < sz ; i ++){
        source[temp[i].S] = mx;
        if(i < sz-1 && temp[i].F != temp[i+1].F) mx++;
    }
    return mx;
}

int compress(vll source){
    ii temp[source.size()]; int mx = 0;
    for(int i = 0 ; i < source.size() ; i ++){
        temp[i].F = source[i];
        temp[i].S = i;
    }
    sort(temp, temp+source.size());
    for(int i = 0 ; i < source.size() ; i ++){
        source[temp[i].S] = mx;
        if(i < source.size()-1 && temp[i].F != temp[i+1].F) mx++;
    }
    return mx;
}
