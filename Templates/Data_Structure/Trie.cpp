#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// -----------------------------------------------------------------

class Trie{
    private:
        static const int sz = 26;
        static int idx(char c){ return c-'a'; }

        struct Node{
            ll all, end;
            Node *next[sz];
            Node(): all(0), end(0) {
                for(int i = 0 ; i < sz ; i ++) next[i] = nullptr;
            }
        };

        Node *root;

    public:
        Trie(): root(new Node) {}

        void insert(string s, ll count = 1){
            Node *cur = root;
            for(int i = 0 ; i < s.size() ; i ++){
                cur->all += count;
                if(!cur->next[idx(s[i])]) cur->next[idx(s[i])] = new Node();
                cur = cur->next[idx(s[i])];
            }
            cur->all += count;
            cur->end += count;
        }

        ll count(string s){
            Node *cur = root;
            for(int i = 0 ; i < s.size() ; i ++){
                if(!cur->next[idx(s[i])]) return 0;
                cur = cur->next[idx(s[i])];
            }
            return cur->end;
        }

        ll max_length(string s, ll count = 1){
            Node *cur = root;
            for(int i = 0 ; i < s.size() ; i ++){
                if(!cur->next[idx(s[i])] || cur->next[idx(s[i])]->all < count) return i;
                cur = cur->next[idx(s[i])];
            }
            return s.size();
        }

        bool remove(string s, ll count = 1){
            Node *cur = root;
            for(int i = 0 ; i < s.size() ; i ++){
                cur->all -= count;
                if(!cur->next[idx(s[i])]) return false;
                cur = cur->next[idx(s[i])];
            }
            cur->all -= count;
            cur->end -= count;
            return 0 <= cur->end;
        }
};

