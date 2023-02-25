#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 9223372036854775807;

// -----------------------------------------------------------------

struct Node{
  ll data;
  Node *left ,*right;
  Node(): data(0) ,left(nullptr) ,right(nullptr) {}
};

// build in O(n) - get in O(logn) - update in O(logn)
class DySegTree{
    private:
        Node *root;
        int seg_str, seg_end;

        // sum, mul, xor, ... || min, max, or, and, gcd, ...
        ll skip_val = -INF;
        ll _conquer(ll a1, ll a2){ return max(a1, a2); }
        void _update_method(ll &a, ll val){
            a = val;   // assign
            // a += val;   // increase
        }

        void _build(Node *& cur, int l, int r, ll a[]){
            if(!cur){ cur = new Node(); }
            if(l == r){
                cur->data = a[l];
                return;
            }
            int m = (l + r)/2;
            _build(cur->left, l, m, a);
            _build(cur->right, m+1, r, a);
            cur->data =_conquer(cur->left->data, cur->right->data);
        }
        
        void _update(int idx, ll val, Node *&cur, int l, int r){
            if(!cur){ cur = new Node(); }
            if(l == r){
                _update_method(cur->data, val);
                return;
            }
            int m = (l + r)/2;
            if(idx <= m) _update(idx, val, cur->left, l, m);
            else _update(idx, val, cur->right, m+1, r);
            cur->data = skip_val;
            if(cur->left) cur->data = _conquer(cur->data, cur->left->data);
            if(cur->right) cur->data = _conquer(cur->data, cur->right->data);
        }

        ll _get(int from, int to, Node *cur, int l, int r){
            if(!cur || to < from) return skip_val;
            if(from == l && to == r) return cur->data;
            int m = (l + r)/2;
            return _conquer(_get(from, min(to,m), cur->left, l, m), _get(max(from,m+1), to, cur->right, m+1, r));
        }
 
    public:
        void resize(int str, int end){
            seg_str = str;
            seg_end = end;
        }

        void build(ll a[]){
            _build(root, seg_str, seg_end, a);
        }
        
        void update(int idx, ll val){
            _update(idx, val, root, seg_str, seg_end);
        }
        
        ll get(int from, int to){
            return _get(from, to, root, seg_str, seg_end);
        }
};
