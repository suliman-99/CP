#include <bits/stdc++.h>
using namespace std;

typedef vector<int>       vi;
typedef vector<vi>        mi;

// -----------------------------------------------------------------

// return the table wich will be used to search by kmp algorithm
// table[i] is the maximum length : s.substr(0, length) == s.substr(i-length+1, i)
vi kmp_table(string &s){
    vi table(s.size());
    int j = 0;
    for(int i = 1 ; i < s.size() ; i ++){
        while(j > 0 && s[i] != s[j]) j = table[j-1];
        if(s[i] == s[j]) j++;
        table[i] = j;
    }
    return table;
}

// return the start indices of s occurrences in text
vi kmp_search(string &s, string &text){
    vi table = kmp_table(s);
    vi res;
    int j = 0;
    for(int i = 0 ; i < text.size() ; i ++){
        while(j > 0 && text[i] != s[j]) j = table[j-1];
        if(text[i] == s[j]) j++;
        if(j == s.size()){
            res.push_back(i-s.size()+1);
            j = table[j-1];
        }
    }
    return res;
}

// return the number of s prefexes occurrences in s
// v[i] = number of occurrences of s.substr(0, i-1) in s
// v[0] is useless value
vi kmp_pre_occ(string &s){
    vi table = kmp_table(s);
    vi res(s.size()+1);
    for(int i = 0 ; i < s.size() ; i ++) res[table[i]]++;
    for(int i = res.size()-1 ; i > 0 ; i --) res[table[i-1]] += res[i];
    for(int i = 1 ; i < res.size() ; i ++) res[i]++; 
    res[0] = -1;
    return res;
}

// return the number of s prefexes occurrences in text
// v[i] = number of occurrences of s.substr(0, i-1) in text
// v[0] is useless value
vi kmp_pre_occ(string &s, string &text){
    string str = s + '#' + text;
    vi table = kmp_table(str);
    vi res(s.size()+1);
    for(int i = 0 ; i < text.size() ; i ++) res[table[s.size()+1+i]]++;
    for(int i = res.size()-1 ; i > 0 ; i --) res[table[i-1]] += res[i];
    res[0] = -1;
    return res;
}

// return the minimum length l : s.substr(0, l-1)*k = s : k is any int
// in the wrost case: l = s.size()
int kmp_min_div_compress(string &s){
    vi table = kmp_table(s);
    int l = s.size() - table[s.size()-1];
    if(s.size()%l) l = s.size();
    return l;
}


// return the next states  (DFA) (Deterministic Finite Automata) (Automaton)
// nxt[j][c-'a'] = the next value of j if c is faced
mi kmp_precalculate_nxt(string &s){
    vi table = kmp_table(s);
    mi nxt = mi(s.size()+1, vi(26));
    for(char c = 'a' ; c <= 'z' ; c ++){
        nxt[0][c-'a'] = (c == s[0]);
        for(int j = 1 ; j <= s.size() ; j ++)
            nxt[j][c-'a'] = ((c == s[j]) ? j+1 : nxt[table[j-1]][c-'a']);
    }
    return nxt;
}

// return the start indices of s occurrences in text
vi kmp_nxt_search(string &s, string &text){
    vi table = kmp_table(s);
    mi nxt = kmp_precalculate_nxt(s);
    vi res;
    for(int i=0, j=0 ; i < text.size() ; i++)
        if((j=nxt[j][text[i]-'a']) == s.size()) res.push_back(i-s.size()+1);
    return res;
}

