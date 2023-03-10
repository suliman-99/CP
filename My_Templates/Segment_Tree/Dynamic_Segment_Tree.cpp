#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 9223372036854775807;

// -----------------------------------------------------------------

// build in O(n) - get in O(logn) - update in O(logn)
class DySegTree{
    private:
        struct Node{
            ll data;
            Node *left ,*right;
            Node(): data(skip_val), left(nullptr), right(nullptr) {}
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
            cur->data = _conquer(cur->left->data, cur->right->data);
        }
        
        static void _update(ll idx, ll val, Node *&cur, ll l, ll r){
            if(!cur){ cur = new Node(); }
            if(l == r){
                _update_method(cur->data, val);
                return;
            }
            ll m = l/2 + r/2 + (l%2 & r%2);
            if(m == r) m = l;
            if(idx <= m) _update(idx, val, cur->left, l, m);
            else _update(idx, val, cur->right, m+1, r);
            cur->data = skip_val;
            if(cur->left) cur->data = _conquer(cur->data, cur->left->data);
            if(cur->right) cur->data = _conquer(cur->data, cur->right->data);
        }

        static ll _get(ll from, ll to, Node *cur, ll l, ll r){
            if(!cur || to < from) return skip_val;
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
        
        void update(ll idx, ll val){
            _update(idx, val, root, seg_str, seg_end);
        }
        
        ll get(ll from, ll to){
            return _get(from, to, root, seg_str, seg_end);
        }
};
