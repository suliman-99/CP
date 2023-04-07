#include <bits/stdc++.h>
using namespace std;

typedef vector<int>       vi;

// -----------------------------------------------------------------

vi kmp_table(string s){
    int m = s.size();
    vi table(m);
    int j = 0;
    for(int i = 1 ; i < m ; i ++){
        while(j > 0 && s[i] != s[j]) j = table[j-1];
        if(s[i] == s[j]) j++;
        table[i] = j;
    }
    return table;
}

vi kmp_search(string text, string s){
    int m = s.size(), n = text.size();
    vi table = kmp_table(s);
    vi res;
    int j = 0;
    for(int i = 0 ; i < n ; i ++){
        while(j > 0 && text[i] != s[j]) j = table[j-1];
        if(text[i] == s[j]) j++;
        if(j == m){
            res.push_back(i-m+1);
            j = table[j-1];
        }
    }
    return res;
}
