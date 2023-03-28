#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 9223372036854775807;

// -----------------------------------------------------------------

// build in O(n) - get in O(logn) - update in O(logn)
class DyLazySegTree{
    private:
        struct Node{
            ll data, lzy;
            bool hav;
            Node *left ,*right;
            Node(): data(skip_val), lzy(0), hav(0), left(nullptr), right(nullptr) {}
        };
        
        Node *root;
        ll seg_str, seg_end;

        // sum, mul, xor, ... || min, max, or, and, gcd, ...
        static const ll skip_val = -INF;
        static ll _conquer(ll a1, ll a2){ return max(a1, a2); }
        static void _update_method(ll &a, ll val){
            a = val;   // assign
            // a += val;   // increase
        }

        // have to be updated to be suitable with update and conquer
        static void _propagate(Node *&cur, ll l, ll r){
            if(!cur){ cur = new Node(); }
            if(!cur->hav) return;
            cur->data = cur->lzy;   // assign & max
            // cur->data += cur->lzy;   // increase & max
            if(l != r){
                if(!cur->left){ cur->left = new Node(); }
                if(!cur->right){ cur->right = new Node(); }
                cur->left->lzy = cur->lzy;   // assign & max
                cur->right->lzy = cur->lzy;   // assign & max
                // cur->left->lzy += cur->lzy;   // increase
                // cur->right->lzy += cur->lzy;   // increase
                cur->left->hav = 1;
                cur->right->hav = 1;
            }
            // cur->lzy = 0;   // increase
            cur->hav = 0;
        }

        static void _build(Node *&cur, ll l, ll r, ll arr[]){
            if(!cur){ cur = new Node(); }
            if(l == r){
                cur->data = arr[l];
                return;
            }
            ll m = l/2 + r/2 + (l%2 & r%2);
            if(m == r) m = l;
            _build(cur->left, l, m, arr);
            _build(cur->right, m+1, r, arr);
            cur->data =_conquer(cur->left->data, cur->right->data);
        }
        
        static void _update(ll from, ll to, ll val, Node *&cur, ll l, ll r){
            _propagate(cur, l, r);
            if(to < from) return;
            if(from == l && to == r){
                cur->lzy = val;   // assign
                // cur->lzy += val;   // increase
                cur->hav = 1;
                _propagate(cur, l, r);
                return;
            }
            ll m = l/2 + r/2 + (l%2 & r%2);
            if(m = r) m = l;
            _update(from, min(to,m), val, cur->left, l, m);
            _update(max(from,m+1), to, val, cur->right, m+1, r);
            cur->data = _conquer(cur->left->data, cur->right->data);
        }

        static ll _get(ll from, ll to, Node *cur, ll l, ll r){
            if(!cur || to < from) return skip_val;
            _propagate(cur, l, r);
            if(from == l && to == r) return cur->data;
            ll m = l/2 + r/2 + (l%2 & r%2);
            if(m == r) m = l;
            return _conquer(_get(from, min(to,m), cur->left, l, m), _get(max(from,m+1), to, cur->right, m+1, r));
        }
 
    public:
        void resize(ll str, ll end){
            seg_str = str;
            seg_end = end;
            root = nullptr;
        }

        void build(ll arr[]){
            _build(root, seg_str, seg_end, arr);
        }
        
        void update(ll from, ll to, ll val){
            _update(from, to, val, root, seg_str, seg_end);
        }
        
        ll get(ll from, ll to){
            return _get(from, to, root, seg_str, seg_end);
        }
};
