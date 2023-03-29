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

// compress the source array & return max element
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


// -------------------------------------------
// there is another technique of compressing
// make a map and fill it ( a[i]: i)
// then use map[a[i]] instead of a[i]
// note: i is the idx idx if we put the elements in a set
// note: i is not the idx in the array

map<ll,ll> compressor;

void map_compress(vll source){
    int idx = 0;
    for(int i = 0 ; i < source.size() ; i ++)
        if(compressor.count(source[i] == 0))
            compressor[source[i]] = idx++;
}